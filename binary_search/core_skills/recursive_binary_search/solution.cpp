#include <vector>
using std::vector;

class Solution
{
public:
    int binSearch(int l, int r, vector<int> &nums, int target)
    {
        if (l > r)
            return -1;
        int m = l + (r - l) / 2;

        if (nums[m] == target)
            return m;
        return ((nums[m] < target) ? binSearch(m + 1, r, nums, target) : binSearch(l, m - 1, nums, target));
    }

    int search(vector<int> &nums, int target)
    {
        return binSearch(0, nums.size() - 1, nums, target);
    }
};