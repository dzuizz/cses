"use client";

import { useState } from "react";
import { Hint } from "@/lib/types";

interface HintRevealerProps {
  hints: Hint[];
}

export default function HintRevealer({ hints }: HintRevealerProps) {
  const [revealedCount, setRevealedCount] = useState(0);

  const revealNext = () => {
    if (revealedCount < hints.length) {
      setRevealedCount(revealedCount + 1);
    }
  };

  const hideAll = () => {
    setRevealedCount(0);
  };

  return (
    <div>
      <div className="flex items-center justify-between mb-4">
        <h2 className="text-xl font-semibold">Hints</h2>
        <div className="flex items-center gap-2">
          <span className="text-sm text-[var(--muted)]">
            {revealedCount} / {hints.length} revealed
          </span>
          {revealedCount > 0 && (
            <button
              onClick={hideAll}
              className="text-xs text-[var(--muted)] hover:text-[var(--foreground)] transition-colors underline"
            >
              Hide all
            </button>
          )}
        </div>
      </div>

      {/* Progress bar */}
      <div className="h-1.5 w-full rounded-full bg-[var(--card-border)] mb-6">
        <div
          className="h-full rounded-full bg-[var(--accent)] transition-all duration-300"
          style={{ width: `${(revealedCount / hints.length) * 100}%` }}
        />
      </div>

      <div className="space-y-3">
        {hints.map((hint, idx) => {
          const isRevealed = idx < revealedCount;
          const isNext = idx === revealedCount;

          return (
            <div
              key={hint.level}
              className={`rounded-lg border transition-all duration-300 ${
                isRevealed
                  ? "border-[var(--hint-border)] bg-[var(--hint-bg)]"
                  : "border-[var(--card-border)] bg-[var(--card)]"
              }`}
            >
              <div className="px-4 py-3">
                <div className="flex items-center gap-2 mb-1">
                  <span
                    className={`inline-flex h-5 w-5 items-center justify-center rounded-full text-xs font-bold ${
                      isRevealed
                        ? "bg-[var(--accent)] text-white"
                        : "bg-[var(--card-border)] text-[var(--muted)]"
                    }`}
                  >
                    {hint.level}
                  </span>
                  <span
                    className={`text-sm font-medium ${
                      isRevealed
                        ? "text-[var(--foreground)]"
                        : "text-[var(--muted)]"
                    }`}
                  >
                    {isRevealed ? hint.title : "Hidden hint"}
                  </span>
                </div>
                {isRevealed && (
                  <p className="text-sm leading-relaxed mt-2 pl-7">
                    {hint.content}
                  </p>
                )}
              </div>
            </div>
          );
        })}
      </div>

      {revealedCount < hints.length && (
        <button
          onClick={revealNext}
          className="mt-4 w-full rounded-lg bg-[var(--accent)] px-4 py-2.5 text-sm font-medium text-white transition-colors hover:bg-[var(--accent-hover)]"
        >
          Reveal Hint {revealedCount + 1}
        </button>
      )}
    </div>
  );
}
