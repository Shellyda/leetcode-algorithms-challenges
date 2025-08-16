#include <climits>
#include <vector>
#include <algorithm>
using std::min;
using std::vector;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, total = 0, len = INT_MAX;

        for (int r = 0; r < nums.size(); r++)
        {
            total += nums[r];

            while (total >= target)
            {
                len = min(len, r - l + 1);
                total -= nums[l];
                l++;
            }
        }

        return len != INT_MAX ? len : 0;
    }
};