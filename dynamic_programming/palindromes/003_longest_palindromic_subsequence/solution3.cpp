#include <vector>
#include <algorithm>
#include <string>
using namespace std;

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