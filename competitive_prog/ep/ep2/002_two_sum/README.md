# sliding window mez

- 🧩 Problem link: [CSES - 1640](https://cses.fi/problemset/task/1640)
- 🚦 Difficulty: C

## Description

You are given an array of `n` integers, and your task is to find two values (at distinct positions) whose sum is `x`.

### Input

- The first input line has two integers `n` and `x`: the array size and the target sum.
- The second line has `n` integers `a_1, a_2, ..., a_n`: the array values.

### Output

- Print two integers: the positions of the values.
- If there are several solutions, you may print any of them.
- If there are no solutions, print `IMPOSSIBLE`.

### Constraints

```
1 ≤ n ≤ 2 ⋅ 10^5
1 ≤ x, a_i ≤ 10^9
```

### Example

**Input:**

```
4 8
2 7 5 1
```

**Output:**

```
2 4
```
