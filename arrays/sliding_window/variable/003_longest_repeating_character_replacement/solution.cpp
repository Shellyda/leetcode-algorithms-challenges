#include <string>
#include <unordered_map>
#include <algorithm>
using std::max;
using std::string;
using std::unordered_map;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> count;
        int len = 0, l = 0, maxFreq = 0;

        for (int r = 0; r < s.size(); r++)
        {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            while ((r - l + 1) - maxFreq > k)
            {
                count[s[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
        }

        return len;
    }
};