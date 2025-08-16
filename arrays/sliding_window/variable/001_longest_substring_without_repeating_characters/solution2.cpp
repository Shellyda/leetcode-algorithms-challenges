/*
 l = 0, len = INT_MIN
 window = set()
 for r in range(len(nums)):
    while(window.count(nums[r]) > 0){
        window.erase(nums[l]);
        l++;
    }
    window.insert(nums[r]);
    len = max(r - l + 1, len)
*/

#include <string>
#include <unordered_set>
#include <algorithm>
using std::max;
using std::string;
using std::unordered_set;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 1)
            return 1;

        int l = 0, len = INT_MIN;
        unordered_set<char> window;

        for (int r = 0; r < s.size(); r++)
        {
            while (window.count(s[r]) > 0)
            {
                window.erase(s[l]);
                l++;
            }

            window.insert(s[r]);
            len = max(r - l + 1, len);
        }

        return len != INT_MIN ? len : 0;
    }
};