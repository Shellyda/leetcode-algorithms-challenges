#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left(nums.size()), res(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            left[i] = i - 1 < 0 ? 1 : left[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int j = left.size() - 1; j >= 0; --j)
        {
            res[j] = left[j] * right;
            right *= nums[j];
        }

        return res;
    }
};
