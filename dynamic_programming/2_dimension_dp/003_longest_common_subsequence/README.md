# Longest Common Subsequence

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/longest-common-subsequence)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- We can go this two ways:
  1. set the `text1` index to be `const` and compare `text2` chars
  2. set the `text2` index to be `const` and compare `text1` chars
- So, every time `text1[i] == text2[j]` we add +1, and if not, move other way
- Using `memo` vector to store ways already visited

## 🕒 Time and Space Complexity

- Time: O(m\*n)
- Space: O(m\*n)

> Where `n` is the number of columns and `m` is the number of rows.

## ✅ Solution

```cpp
class Solution
{
public:
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        memo.resize(m, vector<int>(n, -1));
        return dfs(text1, text2, 0, 0);
    }

    int dfs(string &text1, string &text2, int i, int j)
    {
        if (i == text1.size() || j == text2.size())
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (text1[i] == text2[j])
        {
            memo[i][j] = 1 + dfs(text1, text2, i + 1, j + 1);
        }
        else
        {
            memo[i][j] = max(dfs(text1, text2, i + 1, j),
                             dfs(text1, text2, i, j + 1));
        }
        return memo[i][j];
    }
};
```
