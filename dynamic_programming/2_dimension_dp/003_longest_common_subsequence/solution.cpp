#include <vector>
#include <string>
#include <algorithm>

using std::max;
using std::string;
using std::vector;

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