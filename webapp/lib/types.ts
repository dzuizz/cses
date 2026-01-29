export interface Problem {
  id: string;
  name: string;
  category: string;
  csesUrl: string;
  solutionFile: string;
  solutionCode: string;
  language: string;
}

export interface ProblemsData {
  generatedAt: string | null;
  totalProblems: number;
  problems: Problem[];
}

export interface Hint {
  level: number;
  title: string;
  content: string;
}

export interface Approach {
  algorithm: string;
  description: string;
  keyInsights: string[];
}

export interface Complexity {
  time: string;
  space: string;
  explanation: string;
}

export interface LineExplanation {
  lines: string;
  explanation: string;
}

export interface CodeExplanation {
  overview: string;
  lineByLine: LineExplanation[];
}

export interface Editorial {
  problemId: string;
  problemName: string;
  difficulty: string;
  hints: Hint[];
  approach: Approach;
  complexity: Complexity;
  codeExplanation: CodeExplanation;
}

export interface CategoryGroup {
  category: string;
  problems: Problem[];
}
