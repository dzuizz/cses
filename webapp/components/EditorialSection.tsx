"use client";

import { useState } from "react";
import { Editorial } from "@/lib/types";

interface EditorialSectionProps {
  editorial: Editorial;
}

export default function EditorialSection({ editorial }: EditorialSectionProps) {
  const [isOpen, setIsOpen] = useState(false);

  return (
    <div className="rounded-lg border border-[var(--card-border)]">
      <button
        onClick={() => setIsOpen(!isOpen)}
        className="flex w-full items-center justify-between px-5 py-4 text-left transition-colors hover:bg-[var(--card)]"
      >
        <div className="flex items-center gap-3">
          <h2 className="text-xl font-semibold">Editorial</h2>
          <span className="rounded-full bg-red-100 px-2.5 py-0.5 text-xs font-medium text-red-800 dark:bg-red-900/30 dark:text-red-300">
            Spoiler
          </span>
        </div>
        <svg
          className={`h-5 w-5 text-[var(--muted)] transition-transform duration-200 ${
            isOpen ? "rotate-180" : ""
          }`}
          fill="none"
          viewBox="0 0 24 24"
          stroke="currentColor"
        >
          <path
            strokeLinecap="round"
            strokeLinejoin="round"
            strokeWidth={2}
            d="M19 9l-7 7-7-7"
          />
        </svg>
      </button>

      {isOpen && (
        <div className="border-t border-[var(--card-border)] px-5 py-5 space-y-8">
          {/* Approach */}
          <div>
            <h3 className="text-lg font-semibold mb-2">Approach</h3>
            <div className="inline-block rounded-full bg-[var(--accent)]/10 px-3 py-1 text-xs font-medium text-[var(--accent)] mb-3">
              {editorial.approach.algorithm}
            </div>
            <p className="text-sm leading-relaxed whitespace-pre-line">
              {editorial.approach.description}
            </p>
            {editorial.approach.keyInsights.length > 0 && (
              <div className="mt-4">
                <h4 className="text-sm font-semibold mb-2">Key Insights</h4>
                <ul className="space-y-1.5">
                  {editorial.approach.keyInsights.map((insight, idx) => (
                    <li
                      key={idx}
                      className="flex items-start gap-2 text-sm"
                    >
                      <span className="text-[var(--accent)] mt-0.5">&#8226;</span>
                      <span>{insight}</span>
                    </li>
                  ))}
                </ul>
              </div>
            )}
          </div>

          {/* Complexity */}
          <div>
            <h3 className="text-lg font-semibold mb-3">Complexity Analysis</h3>
            <div className="grid grid-cols-2 gap-3 mb-3">
              <div className="rounded-lg bg-[var(--card)] border border-[var(--card-border)] px-4 py-3">
                <div className="text-xs text-[var(--muted)] mb-1">Time</div>
                <div className="font-mono font-semibold">
                  {editorial.complexity.time}
                </div>
              </div>
              <div className="rounded-lg bg-[var(--card)] border border-[var(--card-border)] px-4 py-3">
                <div className="text-xs text-[var(--muted)] mb-1">Space</div>
                <div className="font-mono font-semibold">
                  {editorial.complexity.space}
                </div>
              </div>
            </div>
            <p className="text-sm text-[var(--muted)]">
              {editorial.complexity.explanation}
            </p>
          </div>

          {/* Code Explanation */}
          <div>
            <h3 className="text-lg font-semibold mb-2">Code Walkthrough</h3>
            <p className="text-sm text-[var(--muted)] mb-4">
              {editorial.codeExplanation.overview}
            </p>
            <div className="space-y-2">
              {editorial.codeExplanation.lineByLine.map((segment, idx) => (
                <div
                  key={idx}
                  className="flex gap-3 rounded-lg bg-[var(--card)] border border-[var(--card-border)] px-4 py-3"
                >
                  <span className="shrink-0 font-mono text-xs text-[var(--accent)] pt-0.5">
                    L{segment.lines}
                  </span>
                  <span className="text-sm">{segment.explanation}</span>
                </div>
              ))}
            </div>
          </div>
        </div>
      )}
    </div>
  );
}
