#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> preF;

    int pivotIndex(vector<int> &nums)
    {
        preF.clear();
        preF.reserve(nums.size());

        int total = 0;
        for (int n : nums)
        {
            total += n;
            preF.push_back(total);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int leftSum = sumRange(0, i - 1);
            int rightSum = sumRange(i + 1, nums.size() - 1);
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }

private:
    int sumRange(int left, int right)
    {
        if (right < left)
            return 0;
        int preRight = (right >= 0) ? preF[right] : 0;
        int preLeft = (left > 0) ? preF[left - 1] : 0;
        return preRight - preLeft;
    }
};
