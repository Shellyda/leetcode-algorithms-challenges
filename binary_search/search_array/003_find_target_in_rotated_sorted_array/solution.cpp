#include <vector>
using std::vector;

class Solution
{
private:
    int binSearch(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int m = l + ((r - l) / 2);

            if (nums[m] > target)
            {
                r = m - 1;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }

        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        if (nums[l] <= nums[r])
        {
            return binSearch(nums, target);
        }

        while (l < r)
        {
            int m = l + ((r - l) / 2);

            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        int deflectionPoint = r;

        vector<int> firstArr(nums.begin(), nums.begin() + deflectionPoint);
        vector<int> secondArr(nums.begin() + deflectionPoint, nums.end());

        int res1 = binSearch(firstArr, target);
        int res2 = binSearch(secondArr, target);

        if (res1 != -1)
        {
            return res1;
        }
        else if (res2 != -1)
        {
            return res2 + deflectionPoint;
        }

        return -1;
    }
};
