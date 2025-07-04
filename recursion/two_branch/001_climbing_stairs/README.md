# Climbing stairs

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/climbing-stairs/description/)
- 🚦 Difficulty: 🟢 Easy

## 🕒 Time and Space Complexity

- Time: O(2^n)
- Space: O(n)

## ✅ Solution 01 - Recursion

```cpp
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
```

## ✅ Solution 02 - Iterative

```cpp
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        int prev1 = 1; // n-2
        int prev2 = 2; // n-1
        int current = 0;

        for (int i = 3; i <= n; ++i)
        {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return current;
    }
```
