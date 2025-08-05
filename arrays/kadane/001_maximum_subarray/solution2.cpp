#include <vector>
#include <algorithm>
using std::max;
using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curSum = 0;
        int maxSum = nums[0];

        for (int n : nums)
        {
            curSum = max(curSum, 0) + n;

            maxSum = max(curSum, maxSum);
        }

        return maxSum;
    }
};
