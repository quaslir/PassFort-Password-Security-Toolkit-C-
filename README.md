PassFort — Password Security Toolkit (C)

A compact, terminal-friendly C utility that helps you evaluate password strength, improve weak passwords, generate secure passwords, and test password lists. Designed for learning and small security exercises.

✨ Highlights

Simple, dependency-free C program (C99-compatible).

Evaluate password strength against common patterns and popular passwords.

Auto-improve weak passwords by injecting missing character classes and extending length.

Random secure password generator with configurable length.

Optional dictionary (rockyou-style) cracking mode (local file required).

Clear, beginner-friendly code — great for learning string handling, randomness and basic security checks.

📦 Features
Menu-driven CLI

1 — Evaluate password strength

2 — Analyze & improve a password

3 — Generate a secure password

4 — Try to crack a password with a local wordlist

5 — Exit

Strength scoring (0–11) factors

Length tiers

Presence of lower-case, upper-case, digits, special characters

Blacklist check against ~100 common passwords

Utilities

Improvement routine that injects missing character types and extends length when needed.

Generator that creates random combinations of letters, digits and symbols.

Basic cracking mode reading from a local file (e.g. rockyou.txt).
