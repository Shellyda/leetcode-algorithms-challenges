#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 1)
            return 1;
        unordered_set<char> set;

        int longest = 0, streak = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (!set.count(s[i]))
            {
                set.insert(s[i]);
                streak++;
            }
            else
            {
                int j = i - 1;
                while (s[j] != s[i])
                {
                    j--;
                }

                i = j + 1;

                set.clear();
                set.insert(s[i]);
                streak = 1;
            }
            longest = max(longest, streak);
        }

        return longest;
    }
};