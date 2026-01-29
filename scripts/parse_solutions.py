#!/usr/bin/env python3
"""Parse solution files from solutions/ directory into data/problems.json."""

import json
import os
import re
from pathlib import Path

# CSES problem categories mapping
CATEGORIES = {
    "Introductory Problems": [
        1068, 1069, 1070, 1071, 1072, 1083, 1092, 1094,
        1617, 1618, 1621, 1622, 1623, 1624, 1754, 1755,
        2165, 2205,
    ],
    "Sorting and Searching": [
        1074, 1084, 1090, 1091, 1163, 1621, 1629, 1640,
        1644, 1645,
    ],
    "Dynamic Programming": [
        1158, 1633, 1634, 1635, 1636, 1637, 1638, 1639,
        1690, 1746,
    ],
    "Graph Algorithms": [
        1192, 1671, 1679,
    ],
    "Range Queries": [
        1143, 1646, 1647, 1648, 1649, 1652, 3220, 3221,
    ],
    "Tree Algorithms": [
        1131, 1135, 1674, 1687, 1688, 1750,
    ],
    "Mathematics": [
        1095, 1712, 1713,
    ],
    "String Algorithms": [
        1080,
    ],
    "Advanced Techniques": [
        2064, 2101, 2214,
    ],
}

# Build reverse mapping: problem_id -> category
ID_TO_CATEGORY = {}
for cat, ids in CATEGORIES.items():
    for pid in ids:
        ID_TO_CATEGORY[pid] = cat


def parse_filename(filename: str) -> dict | None:
    """Extract problem ID and name from filename like '1068-Weird_Algorithm.cpp'."""
    match = re.match(r"^(\d+)-(.+)\.(cpp|py)$", filename)
    if not match:
        return None
    problem_id = match.group(1)
    name = match.group(2).replace("_", " ")
    ext = match.group(3)
    return {
        "id": problem_id,
        "name": name,
        "extension": ext,
        "filename": filename,
    }


def main():
    base_dir = Path(__file__).parent.parent
    solutions_dir = base_dir / "solutions"
    data_dir = base_dir / "data"
    data_dir.mkdir(exist_ok=True)

    problems = []
    seen_ids = set()

    for filename in sorted(os.listdir(solutions_dir)):
        parsed = parse_filename(filename)
        if not parsed:
            continue

        # Skip duplicates (prefer .cpp over .py)
        if parsed["id"] in seen_ids:
            continue
        seen_ids.add(parsed["id"])

        # Read solution code
        solution_path = solutions_dir / filename
        code = solution_path.read_text()

        pid = int(parsed["id"])
        category = ID_TO_CATEGORY.get(pid, "Uncategorized")

        problems.append({
            "id": parsed["id"],
            "name": parsed["name"],
            "category": category,
            "csesUrl": f"https://cses.fi/problemset/task/{parsed['id']}",
            "solutionFile": filename,
            "solutionCode": code,
            "language": "cpp" if parsed["extension"] == "cpp" else "python",
        })

    # Sort by ID
    problems.sort(key=lambda p: int(p["id"]))

    output = {
        "generatedAt": None,  # Will be set by generate_editorials
        "totalProblems": len(problems),
        "problems": problems,
    }

    output_path = data_dir / "problems.json"
    with open(output_path, "w") as f:
        json.dump(output, f, indent=2)

    print(f"Parsed {len(problems)} problems into {output_path}")

    # Print category summary
    cat_counts = {}
    for p in problems:
        cat_counts[p["category"]] = cat_counts.get(p["category"], 0) + 1
    print("\nCategory breakdown:")
    for cat, count in sorted(cat_counts.items()):
        print(f"  {cat}: {count}")


if __name__ == "__main__":
    main()
