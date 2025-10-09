# Road Construction

- 🧩 Problem link: [Codeforces](https://codeforces.com/problemset/problem/330/B)
- 🚦 Difficulty: B

## Description

There are `n` cities and initially no roads between them.  
Every day, a new road is constructed, for a total of `m` roads.

A **component** is a group of cities where there is a route between any two cities using the existing roads.  
After each day, your task is to find:

1. The **number of connected components**, and
2. The **size of the largest component**.

### Input

The first input line has two integers `n` and `m`:  
the number of cities and the number of roads.

Then, there are `m` lines describing the new roads.  
Each line has two integers `a` and `b`: a new road is constructed between cities `a` and `b`.

You may assume that every road will be constructed between **two different cities**.

### Output

Print `m` lines, each containing two integers:

- The **number of components**, and
- The **size of the largest component**,

after the road of that day has been built.

### Constraints

1 ≤ n ≤ 10⁵
1 ≤ m ≤ 2⋅10⁵
1 ≤ a, b ≤ n

### Example

**Input:**
5 3
1 2
1 3
4 5

**Output:**
4 2
3 3
2 3
