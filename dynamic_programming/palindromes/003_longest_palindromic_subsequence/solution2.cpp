#include <utility>
#include <string>
#include <algorithm>
using namespace std;

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