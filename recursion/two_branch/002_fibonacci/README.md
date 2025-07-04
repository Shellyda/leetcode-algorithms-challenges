# Fibonacci

- 🧩 Problem link: [Leetcode](https://leetcode.com/problemset/all/)
- 🚦 Difficulty: 🟢 Easy

## 🕒 Time and Space Complexity

- Time: O(2^n)
- Space: O(n)

## ✅ Solution 01 - Recursive

```cpp
// Recursive implementation to calculate the n-th Fibonacci number
int fibonacci(int n)
{
    // Base case: n = 0 or 1
    if (n <= 1)
    {
        return n;
    }
    // Recursive case: fib(n) = fib(n - 1) + fib(n - 2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

```

## ✅ Solution 02 - Iterative

```cpp
int fibonacci(int n)
{
    if (n <= 0)
        return;

    int a = 0, b = 1;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        long long nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
}
```

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)
