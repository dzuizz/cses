import type { Metadata } from "next";
import { Geist, Geist_Mono } from "next/font/google";
import Link from "next/link";
import "./globals.css";

const geistSans = Geist({
  variable: "--font-geist-sans",
  subsets: ["latin"],
});

const geistMono = Geist_Mono({
  variable: "--font-geist-mono",
  subsets: ["latin"],
});

export const metadata: Metadata = {
  title: "CSES Solutions",
  description:
    "Solutions, editorials, and progressive hints for CSES Problem Set",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body
        className={`${geistSans.variable} ${geistMono.variable} antialiased`}
      >
        <header className="sticky top-0 z-50 border-b border-[var(--card-border)] bg-[var(--background)]/80 backdrop-blur-md">
          <div className="mx-auto flex max-w-5xl items-center justify-between px-6 py-4">
            <Link
              href="/"
              className="text-xl font-bold tracking-tight hover:opacity-80 transition-opacity"
            >
              CSES Solutions
            </Link>
            <nav className="flex items-center gap-4 text-sm text-[var(--muted)]">
              <a
                href="https://cses.fi/problemset/"
                target="_blank"
                rel="noopener noreferrer"
                className="hover:text-[var(--foreground)] transition-colors"
              >
                CSES Problem Set
              </a>
              <a
                href="https://github.com/dzuizz/cses"
                target="_blank"
                rel="noopener noreferrer"
                className="hover:text-[var(--foreground)] transition-colors"
              >
                GitHub
              </a>
            </nav>
          </div>
        </header>

        <main className="mx-auto max-w-5xl px-6 py-8">{children}</main>

        <footer className="border-t border-[var(--card-border)] py-8 text-center text-sm text-[var(--muted)]">
          <div className="mx-auto max-w-5xl px-6">
            <p>
              Built with Next.js. Solutions for the{" "}
              <a
                href="https://cses.fi/problemset/"
                target="_blank"
                rel="noopener noreferrer"
                className="underline hover:text-[var(--foreground)]"
              >
                CSES Problem Set
              </a>
              .
            </p>
          </div>
        </footer>
      </body>
    </html>
  );
}
