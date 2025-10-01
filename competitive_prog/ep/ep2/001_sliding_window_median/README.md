# Sliding window median

- 🧩 Problem link: [CSES - 1076](https://cses.fi/problemset/task/1076)
- 🚦 Difficulty: E

## Description

You are given an array of `n` integers.  
Your task is to calculate the **median** of each window of `k` elements, from left to right.

The **median** is defined as:

- The middle element when the elements are sorted.
- If the number of elements is even, there are two possible medians, and we assume the median is the **smaller one**.

### Input

- The first line contains two integers `n` and `k`: the number of elements and the size of the window.
- Then there are `n` integers `x_1, x_2, ..., x_n`: the contents of the array.

### Output

- Print `n-k+1` values: the medians.

### Constraints

```
1 ≤ k ≤ n ≤ 2 ⋅ 10^5
1 ≤ x_i ≤ 10^9
```

### Example

**Input:**

```
8 3
2 4 3 5 8 1 2 1
```

**Output:**

```
3 4 5 5 2 1
```
