#include <vector>
#include <algorithm>
using std::max;
using std::vector;

int bruteForce(vector<int> &nums)
{
    int maxSum = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        int curSum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            curSum += nums[j];
            maxSum = max(maxSum, curSum);
        }
    }
    return maxSum;
};