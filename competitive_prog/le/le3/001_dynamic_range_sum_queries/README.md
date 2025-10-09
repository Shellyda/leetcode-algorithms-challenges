# Dynamic Range Sum Queries

- 🧩 Problem link: [CSES](https://cses.fi/alon/task/1648)
- 🚦 Difficulty: A

## Description

Given an array of `n` integers, your task is to process `q` queries of the following types:

1. **Update** the value at position `k` to `u`.
2. **Query** the sum of values in range `[a, b]`.

### Input

The first input line has two integers `n` and `q`:  
the number of values and the number of queries.

The second line has `n` integers:  
`x₁, x₂, …, xₙ` — the array values.

Finally, there are `q` lines describing the queries.  
Each line has three integers, either:

- `1 k u` — set `xₖ = u`
- `2 a b` — print the sum of values in range `[a, b]`

### Output

Print the result of each query of type `2`.

### Constraints

1 ≤ n, q ≤ 2⋅10⁵
1 ≤ xᵢ, u ≤ 10⁹
1 ≤ k ≤ n
1 ≤ a ≤ b ≤ n

### Example

**Input:**

```
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
```

**Output:**

```
14
2
11
```
