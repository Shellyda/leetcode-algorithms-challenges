# Climbing Stairs

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/climbing-stairs/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Using memoization to change my prev answer

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    int climbStairs(int n)
    {
        unordered_map<int, int> cache;
        return memoization(n, cache);
    }

private:
    int memoization(int n, unordered_map<int, int> &cache)
    {
        if (n <= 2)
            return n;

        if (cache.count(n))
            return cache[n];

        int result = memoization(n - 1, cache) + memoization(n - 2, cache);
        cache[n] = result;

        return cache.at(n);
    }
};
```
