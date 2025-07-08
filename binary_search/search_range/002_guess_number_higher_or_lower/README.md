# Guess Number Higher or Lower

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/guess-number-higher-or-lower/description/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Use `binSearch` concept

## 🕒 Time and Space Complexity

- Time: O(logn)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n;

        while (l <= r)
        {
            int m = l + ((r - l) / 2);

            if (guess(m) < 0)
            {
                r = m - 1;
            }
            else if (guess(m) > 0)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }

        return -1;
    }
};
```
