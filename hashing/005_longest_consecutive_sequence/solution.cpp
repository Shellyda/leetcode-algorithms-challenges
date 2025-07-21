#include <unordered_set>
#include <vector>
#include <algorithm>
using std::max;
using std::unordered_set;
using std::vector;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet)
        {
            if (!numSet.count(num - 1))
            {
                int streak = 1;
                while (numSet.count(num + streak))
                {
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};