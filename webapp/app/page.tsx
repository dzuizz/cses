import Link from "next/link";
import { getProblemsByCategory } from "@/lib/problems";

const CATEGORY_COLORS: Record<string, string> = {
  "Introductory Problems": "bg-green-100 text-green-800 dark:bg-green-900/30 dark:text-green-300",
  "Sorting and Searching": "bg-blue-100 text-blue-800 dark:bg-blue-900/30 dark:text-blue-300",
  "Dynamic Programming": "bg-purple-100 text-purple-800 dark:bg-purple-900/30 dark:text-purple-300",
  "Graph Algorithms": "bg-orange-100 text-orange-800 dark:bg-orange-900/30 dark:text-orange-300",
  "Range Queries": "bg-red-100 text-red-800 dark:bg-red-900/30 dark:text-red-300",
  "Tree Algorithms": "bg-teal-100 text-teal-800 dark:bg-teal-900/30 dark:text-teal-300",
  Mathematics: "bg-yellow-100 text-yellow-800 dark:bg-yellow-900/30 dark:text-yellow-300",
  "String Algorithms": "bg-pink-100 text-pink-800 dark:bg-pink-900/30 dark:text-pink-300",
  "Advanced Techniques": "bg-indigo-100 text-indigo-800 dark:bg-indigo-900/30 dark:text-indigo-300",
};

export default function Home() {
  const categories = getProblemsByCategory();
  const totalProblems = categories.reduce(
    (sum, cat) => sum + cat.problems.length,
    0
  );

  return (
    <div>
      <section className="mb-12">
        <h1 className="text-4xl font-bold tracking-tight mb-3">
          CSES Problem Set Solutions
        </h1>
        <p className="text-lg text-[var(--muted)] mb-4">
          {totalProblems} solved problems with solutions, progressive hints, and
          detailed editorials.
        </p>
        <div className="flex gap-2 flex-wrap">
          {categories.map((cat) => (
            <a
              key={cat.category}
              href={`#${cat.category.toLowerCase().replace(/\s+/g, "-")}`}
              className={`inline-block rounded-full px-3 py-1 text-xs font-medium transition-opacity hover:opacity-80 ${
                CATEGORY_COLORS[cat.category] || "bg-gray-100 text-gray-800 dark:bg-gray-800 dark:text-gray-300"
              }`}
            >
              {cat.category} ({cat.problems.length})
            </a>
          ))}
        </div>
      </section>

      {categories.map((cat) => (
        <section
          key={cat.category}
          id={cat.category.toLowerCase().replace(/\s+/g, "-")}
          className="mb-10"
        >
          <h2 className="text-2xl font-semibold mb-4 flex items-center gap-3">
            <span
              className={`inline-block rounded-full px-3 py-1 text-xs font-medium ${
                CATEGORY_COLORS[cat.category] || "bg-gray-100 text-gray-800 dark:bg-gray-800 dark:text-gray-300"
              }`}
            >
              {cat.problems.length}
            </span>
            {cat.category}
          </h2>
          <div className="grid gap-2">
            {cat.problems.map((problem) => (
              <Link
                key={problem.id}
                href={`/problems/${problem.id}`}
                className="group flex items-center justify-between rounded-lg border border-[var(--card-border)] bg-[var(--card)] px-4 py-3 transition-all hover:border-[var(--accent)] hover:shadow-sm"
              >
                <div className="flex items-center gap-3">
                  <span className="font-mono text-sm text-[var(--muted)]">
                    {problem.id}
                  </span>
                  <span className="font-medium group-hover:text-[var(--accent)] transition-colors">
                    {problem.name}
                  </span>
                </div>
                <span className="text-xs text-[var(--muted)] uppercase tracking-wider">
                  {problem.language}
                </span>
              </Link>
            ))}
          </div>
        </section>
      ))}
    </div>
  );
}
