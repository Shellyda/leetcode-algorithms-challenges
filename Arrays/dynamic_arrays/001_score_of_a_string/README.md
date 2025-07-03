# Score of a String

- 🧩 Problem link: [Leetcode](https://leetcode.com/problemset/all/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Loop to all string characters and use a counter to get the score
- Watch out to don't go out of bounds

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
int scoreOfString(string s)
    {
        int res = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            res += abs(s[i] - s[i + 1]);
        }

        return res;
    }
```
