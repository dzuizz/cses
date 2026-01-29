import fs from "fs";
import path from "path";
import { Problem, ProblemsData, Editorial, CategoryGroup } from "./types";

const DATA_DIR = path.join(process.cwd(), "..", "data");

export function getProblemsData(): ProblemsData {
  const filePath = path.join(DATA_DIR, "problems.json");
  const raw = fs.readFileSync(filePath, "utf-8");
  return JSON.parse(raw);
}

export function getAllProblems(): Problem[] {
  return getProblemsData().problems;
}

export function getProblemById(id: string): Problem | undefined {
  return getAllProblems().find((p) => p.id === id);
}

export function getEditorial(problemId: string): Editorial | null {
  const filePath = path.join(DATA_DIR, "editorials", `${problemId}.json`);
  if (!fs.existsSync(filePath)) {
    return null;
  }
  const raw = fs.readFileSync(filePath, "utf-8");
  return JSON.parse(raw);
}

export function getProblemsByCategory(): CategoryGroup[] {
  const problems = getAllProblems();
  const categoryOrder = [
    "Introductory Problems",
    "Sorting and Searching",
    "Dynamic Programming",
    "Graph Algorithms",
    "Range Queries",
    "Tree Algorithms",
    "Mathematics",
    "String Algorithms",
    "Advanced Techniques",
  ];

  const grouped: Record<string, Problem[]> = {};
  for (const p of problems) {
    if (!grouped[p.category]) {
      grouped[p.category] = [];
    }
    grouped[p.category].push(p);
  }

  const result: CategoryGroup[] = [];
  for (const cat of categoryOrder) {
    if (grouped[cat]) {
      result.push({ category: cat, problems: grouped[cat] });
    }
  }

  // Add any remaining categories not in the order list
  for (const cat of Object.keys(grouped)) {
    if (!categoryOrder.includes(cat)) {
      result.push({ category: cat, problems: grouped[cat] });
    }
  }

  return result;
}

export function getAllProblemIds(): string[] {
  return getAllProblems().map((p) => p.id);
}
