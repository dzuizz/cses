import Link from "next/link";
import { notFound } from "next/navigation";
import {
  getProblemById,
  getEditorial,
  getAllProblemIds,
} from "@/lib/problems";
import CodeViewer from "@/components/CodeViewer";
import HintRevealer from "@/components/HintRevealer";
import EditorialSection from "@/components/EditorialSection";

interface PageProps {
  params: Promise<{ problemId: string }>;
}

export async function generateStaticParams() {
  const ids = getAllProblemIds();
  return ids.map((id) => ({ problemId: id }));
}

export async function generateMetadata({ params }: PageProps) {
  const { problemId } = await params;
  const problem = getProblemById(problemId);
  if (!problem) return { title: "Problem Not Found" };
  return {
    title: `${problem.name} - CSES Solutions`,
    description: `Solution and editorial for CSES problem ${problem.id}: ${problem.name}`,
  };
}

export default async function ProblemPage({ params }: PageProps) {
  const { problemId } = await params;
  const problem = getProblemById(problemId);
  if (!problem) notFound();

  const editorial = getEditorial(problemId);

  return (
    <div>
      {/* Breadcrumb */}
      <nav className="mb-6 text-sm text-[var(--muted)]">
        <Link href="/" className="hover:text-[var(--foreground)] transition-colors">
          Problems
        </Link>
        <span className="mx-2">/</span>
        <span className="text-[var(--foreground)]">{problem.name}</span>
      </nav>

      {/* Header */}
      <div className="mb-8">
        <div className="flex items-center gap-3 mb-2">
          <span className="font-mono text-sm text-[var(--muted)]">
            #{problem.id}
          </span>
          <span className="rounded-full bg-[var(--accent)]/10 px-3 py-0.5 text-xs font-medium text-[var(--accent)]">
            {problem.category}
          </span>
          {editorial && (
            <span
              className={`rounded-full px-3 py-0.5 text-xs font-medium ${
                editorial.difficulty === "Easy"
                  ? "bg-green-100 text-green-800 dark:bg-green-900/30 dark:text-green-300"
                  : editorial.difficulty === "Medium"
                  ? "bg-yellow-100 text-yellow-800 dark:bg-yellow-900/30 dark:text-yellow-300"
                  : "bg-red-100 text-red-800 dark:bg-red-900/30 dark:text-red-300"
              }`}
            >
              {editorial.difficulty}
            </span>
          )}
        </div>
        <h1 className="text-3xl font-bold tracking-tight mb-3">
          {problem.name}
        </h1>
        <a
          href={problem.csesUrl}
          target="_blank"
          rel="noopener noreferrer"
          className="inline-flex items-center gap-1.5 text-sm text-[var(--accent)] hover:underline"
        >
          View on CSES
          <svg className="h-3.5 w-3.5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2} d="M10 6H6a2 2 0 00-2 2v10a2 2 0 002 2h10a2 2 0 002-2v-4M14 4h6m0 0v6m0-6L10 14" />
          </svg>
        </a>
      </div>

      {/* Hints Section */}
      {editorial && editorial.hints.length > 0 && (
        <section className="mb-8">
          <HintRevealer hints={editorial.hints} />
        </section>
      )}

      {/* Solution Code */}
      <section className="mb-8">
        <h2 className="text-xl font-semibold mb-4">Solution</h2>
        <CodeViewer
          code={problem.solutionCode}
          language={problem.language}
          filename={problem.solutionFile}
        />
      </section>

      {/* Editorial */}
      {editorial && (
        <section className="mb-8">
          <EditorialSection editorial={editorial} />
        </section>
      )}

      {/* No editorial fallback */}
      {!editorial && (
        <section className="mb-8 rounded-lg border border-[var(--card-border)] bg-[var(--card)] px-5 py-4">
          <p className="text-sm text-[var(--muted)]">
            Editorial not yet generated for this problem. Run the editorial
            generation script to add hints and detailed explanations.
          </p>
        </section>
      )}
    </div>
  );
}
