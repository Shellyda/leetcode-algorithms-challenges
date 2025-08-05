# Find the Index of the First Occurrence in a String

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

We iterate through the `haystack` using a sliding window of length equal to the `needle`.
At each position, we extract a substring and compare it to the `needle`.

- If a match is found, return the current index.
- If no match is found after checking all valid positions, return `-1`.

## 🕒 Time and Space Complexity

- Time: O(n \* m)
- Space: O(m) for the substring

> Where `n = haystack size`, `m = needle size`

## ✅ Solution

```cpp
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;
        if (m > n)
            return -1;

        for (int i = 0; i <= n - m; i++)
        {
            if (haystack.substr(i, m) == needle)
            {
                return i;
            }
        }

        return -1;
    }
};
```
