#!/usr/bin/env python3
"""Generate editorials for CSES solutions using Claude API.

Usage:
    python generate_editorials.py                  # Generate for new/changed solutions
    python generate_editorials.py --force          # Regenerate all editorials
    python generate_editorials.py --limit 3        # Only generate for first 3 missing
    python generate_editorials.py --problem 1068   # Generate for specific problem
"""

import argparse
import hashlib
import json
import os
import sys
from pathlib import Path

try:
    import anthropic
    from dotenv import load_dotenv
except ImportError:
    print("Missing dependencies. Run: pip install -r scripts/requirements.txt")
    sys.exit(1)

load_dotenv()

BASE_DIR = Path(__file__).parent.parent
DATA_DIR = BASE_DIR / "data"
EDITORIALS_DIR = DATA_DIR / "editorials"
PROBLEMS_JSON = DATA_DIR / "problems.json"
HASH_CACHE = DATA_DIR / ".editorial_hashes.json"

EDITORIAL_PROMPT = """You are an expert competitive programming tutor. Analyze the following C++ solution for the CSES problem "{problem_name}" (ID: {problem_id}).

The solution code:
```cpp
{code}
```

The problem is from the CSES Problem Set, category: {category}.
Problem URL: https://cses.fi/problemset/task/{problem_id}

Generate a comprehensive editorial in the following JSON format. Be precise and educational.

{{
  "problemName": "{problem_name}",
  "problemId": "{problem_id}",
  "difficulty": "<one of: Easy, Medium, Hard>",
  "hints": [
    {{
      "level": 1,
      "title": "<vague direction hint title>",
      "content": "<A gentle nudge toward the right approach without revealing the algorithm. Think about what data structure or technique category might help.>"
    }},
    {{
      "level": 2,
      "title": "<technique hint title>",
      "content": "<Mention the general technique/algorithm family without full details. E.g., 'Consider using dynamic programming' or 'Think about graph traversal'.>"
    }},
    {{
      "level": 3,
      "title": "<approach hint title>",
      "content": "<Describe the approach at a high level. What are the key observations? What subproblems do you need to solve?>"
    }},
    {{
      "level": 4,
      "title": "<implementation hint title>",
      "content": "<Give specific implementation guidance. What state do you track? What transitions exist? What edge cases matter?>"
    }},
    {{
      "level": 5,
      "title": "<detailed solution hint title>",
      "content": "<Nearly complete description of the solution. Someone reading this should be able to code it.>"
    }}
  ],
  "approach": {{
    "algorithm": "<Name of the primary algorithm/technique>",
    "description": "<2-3 paragraph explanation of the overall approach and why it works>",
    "keyInsights": [
      "<Key insight 1>",
      "<Key insight 2>",
      "<Key insight 3>"
    ]
  }},
  "complexity": {{
    "time": "<Time complexity, e.g., O(n log n)>",
    "space": "<Space complexity, e.g., O(n)>",
    "explanation": "<Brief explanation of why these complexities hold>"
  }},
  "codeExplanation": {{
    "overview": "<1-2 sentence overview of what the code does>",
    "lineByLine": [
      {{
        "lines": "<line range, e.g., 1-3>",
        "explanation": "<What these lines do>"
      }}
    ]
  }}
}}

IMPORTANT: Return ONLY the JSON object, no markdown fences, no extra text."""


def compute_hash(code: str) -> str:
    return hashlib.md5(code.encode()).hexdigest()


def load_hash_cache() -> dict:
    if HASH_CACHE.exists():
        return json.loads(HASH_CACHE.read_text())
    return {}


def save_hash_cache(cache: dict):
    HASH_CACHE.write_text(json.dumps(cache, indent=2))


def generate_editorial(client: anthropic.Anthropic, problem: dict) -> dict:
    """Generate editorial for a single problem using Claude API."""
    prompt = EDITORIAL_PROMPT.format(
        problem_name=problem["name"],
        problem_id=problem["id"],
        code=problem["solutionCode"],
        category=problem["category"],
    )

    message = client.messages.create(
        model="claude-sonnet-4-20250514",
        max_tokens=4096,
        messages=[{"role": "user", "content": prompt}],
    )

    response_text = message.content[0].text.strip()

    # Try to parse JSON, handling potential markdown fences
    if response_text.startswith("```"):
        lines = response_text.split("\n")
        response_text = "\n".join(lines[1:-1])

    return json.loads(response_text)


def main():
    parser = argparse.ArgumentParser(description="Generate CSES editorials with Claude API")
    parser.add_argument("--force", action="store_true", help="Regenerate all editorials")
    parser.add_argument("--limit", type=int, default=0, help="Limit number of generations")
    parser.add_argument("--problem", type=str, help="Generate for specific problem ID")
    parser.add_argument("--dry-run", action="store_true", help="Show what would be generated")
    args = parser.parse_args()

    if not PROBLEMS_JSON.exists():
        print("Error: data/problems.json not found. Run parse_solutions.py first.")
        sys.exit(1)

    api_key = os.getenv("ANTHROPIC_API_KEY")
    if not api_key and not args.dry_run:
        print("Error: ANTHROPIC_API_KEY not set. Add it to .env or export it.")
        sys.exit(1)

    problems_data = json.loads(PROBLEMS_JSON.read_text())
    problems = problems_data["problems"]
    EDITORIALS_DIR.mkdir(parents=True, exist_ok=True)

    hash_cache = load_hash_cache()
    to_generate = []

    for problem in problems:
        pid = problem["id"]

        if args.problem and pid != args.problem:
            continue

        editorial_path = EDITORIALS_DIR / f"{pid}.json"
        code_hash = compute_hash(problem["solutionCode"])

        if not args.force and editorial_path.exists():
            cached_hash = hash_cache.get(pid)
            if cached_hash == code_hash:
                continue  # No changes, skip

        to_generate.append((problem, editorial_path, code_hash))

    if not to_generate:
        print("All editorials are up to date!")
        return

    if args.limit > 0:
        to_generate = to_generate[: args.limit]

    print(f"Will generate editorials for {len(to_generate)} problems:")
    for problem, _, _ in to_generate:
        print(f"  [{problem['id']}] {problem['name']}")

    if args.dry_run:
        return

    client = anthropic.Anthropic(api_key=api_key)
    generated = 0
    errors = 0

    for problem, editorial_path, code_hash in to_generate:
        pid = problem["id"]
        print(f"\nGenerating editorial for [{pid}] {problem['name']}...")

        try:
            editorial = generate_editorial(client, problem)
            editorial_path.write_text(json.dumps(editorial, indent=2))
            hash_cache[pid] = code_hash
            save_hash_cache(hash_cache)
            generated += 1
            print(f"  Done! Saved to {editorial_path}")
        except json.JSONDecodeError as e:
            print(f"  ERROR: Failed to parse JSON response: {e}")
            errors += 1
        except anthropic.APIError as e:
            print(f"  ERROR: API error: {e}")
            errors += 1
        except Exception as e:
            print(f"  ERROR: Unexpected error: {e}")
            errors += 1

    print(f"\nComplete! Generated: {generated}, Errors: {errors}")


if __name__ == "__main__":
    main()
