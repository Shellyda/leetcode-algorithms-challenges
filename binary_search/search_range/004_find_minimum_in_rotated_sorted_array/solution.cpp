#include <vector>

class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return nums[l];
    }
};