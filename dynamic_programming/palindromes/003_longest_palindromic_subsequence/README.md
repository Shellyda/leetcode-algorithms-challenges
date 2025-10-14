# Longest Palindromic Subsequence

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/longest-palindromic-subsequence)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

To solve the Longest Palindromic Subsequence problem, we use dynamic programming with memoization. The main idea is to use a recursive function (`dfs`) to explore all possible subsequences and cache the results to avoid redundant calculations. For each character in the string, we try to expand around it (both for odd and even length palindromes) and keep track of the maximum length found.

- **Solution 01 and 02** use a `map<pair<int, int>, int>` as a cache to store results for subproblems. They recursively check for matching characters at the current left and right indices and expand outwards. However, these solutions use a map for memoization, which is less efficient and can lead to higher memory usage and slower lookups, especially for large input sizes. Additionally, Solution 02 has a subtle bug in its base case: it checks `r > str.size()` instead of `r >= str.size()`, which can cause out-of-bounds access.

- **Solution 03** uses a 2D vector (`vector<vector<int>> dp`) for memoization, which is more efficient in both time and space for this problem. The 2D DP table allows for constant-time lookups and updates, and it avoids the overhead of using a map. This approach is optimal for problems with fixed-size subproblems like this one.

**Only Solution 03 was accepted** because it uses a 2D DP array for memoization, which is both faster and more memory-efficient than using a map. The map-based solutions are prone to time and memory limit exceeded errors on large inputs, while the DP table approach fits the problem constraints and passes all test cases efficiently.

## 🕒 Time and Space Complexity

- **Time Complexity:**

  - For the optimal 2D DP solution (Solution 03), the time complexity is **O(n²)**, where _n_ is the length of the input string. This is because each subproblem defined by the pair of indices _(i, j)_ is solved once, and there are O(n²) such pairs.
  - The map-based solutions also have O(n²) subproblems, but due to the overhead of map operations, they are slower in practice.

- **Space Complexity:**
  - The 2D DP solution uses **O(n²)** space for the DP table.
  - The map-based solutions also use up to O(n²) space for memoization, but with higher overhead due to the map structure.

## ✅ Solution

```cpp
class Solution
{
public:
    map<pair<int, int>, int> cache;
    string str;
    int longestPalindromeSubseq(string s)
    {
        str = s;
        int longest = 0;

        for (int i = 0; i < s.size(); i++)
        {
            longest = max(longest, dfs(i, i));     // odd
            longest = max(longest, dfs(i, i + 1)); // even
        }

        return longest;
    }
    int dfs(int l, int r)
    {
        if (l < 0 || r >= str.size())
            return 0;

        pair<int, int> key = {l, r};

        if (cache.count(key))
            return cache[key];

        int result = 0;
        if (str[l] == str[r])
        {
            int length = l == r ? 1 : 2;
            result = length + dfs(l - 1, r + 1);
        }
        else
        {
            result = max(dfs(l - 1, r), dfs(l, r + 1));
        }

        cache[key] = result;

        return result;
    }
};
```

## ✅ Solution 02

```cpp
class Solution
{
public:
    map<pair<int, int>, int> cache;
    string str;
    int longestPalindromeSubseq(string s)
    {
        str = s;
        for (int i = 0; i < s.size(); i++)
        {
            dfs(i, i);
            dfs(i, i + 1);
        }
        auto maxIt = max_element(cache.begin(), cache.end(),
                                 [](const auto &p1, const auto &p2)
                                 {
                                     return p1.second < p2.second;
                                 });
        return maxIt->second;
    }
    int dfs(int l, int r)
    {
        if (l < 0 || r > str.size())
            return 0;
        if (cache.count({l, r}))
            return cache[{l, r}];

        if (str[l] == str[r])
        {
            int length = l == r ? 1 : 2;
            cache[{l, r}] = length + dfs(l - 1, r + 1);
        }
        else
        {
            cache[{l, r}] = max(dfs(l - 1, r), dfs(l, r + 1));
        }

        return cache[{l, r}];
    }
};
```

## ✅ Solution 03

```cpp
class Solution
{
private:
    vector<vector<int>> dp;

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            dfs(i, i, s);     // odd
            dfs(i, i + 1, s); // even
        }

        int maxLength = 0;
        for (const auto &row : dp)
        {
            for (int val : row)
            {
                maxLength = max(maxLength, val);
            }
        }

        return maxLength;
    }

private:
    int dfs(int i, int j, const string &s)
    {
        if (i < 0 || j == s.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == s[j])
        {
            int length = (i == j) ? 1 : 2;
            dp[i][j] = length + dfs(i - 1, j + 1, s);
        }
        else
        {
            dp[i][j] = max(dfs(i - 1, j, s), dfs(i, j + 1, s));
        }

        return dp[i][j];
    }
};
```
