#include <vector>
#include <algorithm>
using std::max;
using std::vector;

// Return the left and right index of the max subarray sum,
// assuming there's exactly one result (no ties).
// Sliding window variation of Kadane's: O(n)
vector<int> slidingWindow(vector<int> nums)
{
    int maxSum = nums[0];
    int curSum = 0;
    int maxL = 0, maxR = 0;
    int L = 0;

    for (int R = 0; R < nums.size(); R++)
    {
        if (curSum < 0)
        {
            curSum = 0;
            L = R;
        }
        curSum += nums[R];
        if (curSum > maxSum)
        {
            maxSum = curSum;
            maxL = L;
            maxR = R;
        }
    }
    return vector<int>{maxL, maxR};
};