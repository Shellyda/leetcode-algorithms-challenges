#include <utility>
#include <map>
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