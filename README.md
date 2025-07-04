# Leetcode Study Vault

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg" />
  <img src="https://img.shields.io/badge/Leetcode-Study-yellow.svg" />
  <img src="https://img.shields.io/badge/Problems_Solved-0-green" />
  <img src="https://img.shields.io/badge/Automated_README-✔️-success" />
</p>

This repository was created as a way to deepen understanding of **algorithms** and **data structures** by solving problems from Leetcode.
Each solution is documented to serve as both a **reference** and a **personal learning log**.

> It is structured in a way that makes it easy to review, revisit, and expand my problem-solving knowledge over time.

## Topics

- [Arrays](./Arrays)
- [linked_lists](./linked_lists)
- [Questions](./Questions)

## Repository Structure

Organized by topic (e.g., `arrays`, `graph`, `dp`). Each problem is in a numbered folder with a slug:

```
📁 arrays/
  ├── 001_two_sum/
  │   ├── solution.cpp
  │   └── README.md
```

## How to Add a New Problem
I created this script to help with documentation and repository organization. Here's how to use it:

#### 1. Make the script executable:
```bash
chmod +x add_problem.sh
```

#### 2. Run it:
```bash
./add_problem.sh
```

It will prompt you for:
- Category (e.g., `arrays/binarysearch`)
- Problem title
- Difficulty (optional)

It then creates a folder with:
- `solution.cpp`
- `README.md`
And updates all README files automatically.

