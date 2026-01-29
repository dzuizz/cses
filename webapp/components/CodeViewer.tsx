"use client";

import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import { vscDarkPlus } from "react-syntax-highlighter/dist/esm/styles/prism";
import { useState } from "react";

interface CodeViewerProps {
  code: string;
  language: string;
  filename?: string;
}

export default function CodeViewer({
  code,
  language,
  filename,
}: CodeViewerProps) {
  const [copied, setCopied] = useState(false);

  const handleCopy = async () => {
    await navigator.clipboard.writeText(code);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  const langMap: Record<string, string> = {
    cpp: "cpp",
    python: "python",
    py: "python",
  };

  return (
    <div className="rounded-lg border border-[var(--card-border)] overflow-hidden">
      <div className="flex items-center justify-between bg-[#1e1e1e] px-4 py-2 text-sm">
        <span className="text-gray-400 font-mono">
          {filename || `solution.${language === "python" ? "py" : "cpp"}`}
        </span>
        <button
          onClick={handleCopy}
          className="text-gray-400 hover:text-white transition-colors px-2 py-1 rounded text-xs"
        >
          {copied ? "Copied!" : "Copy"}
        </button>
      </div>
      <SyntaxHighlighter
        language={langMap[language] || language}
        style={vscDarkPlus}
        showLineNumbers
        customStyle={{
          margin: 0,
          borderRadius: 0,
          fontSize: "0.875rem",
        }}
      >
        {code.trim()}
      </SyntaxHighlighter>
    </div>
  );
}
