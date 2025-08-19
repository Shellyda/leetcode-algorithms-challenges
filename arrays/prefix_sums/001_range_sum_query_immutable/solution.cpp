#include <vector>
using std::vector;

class NumArray
{
public:
    vector<int> preFix;
    NumArray(vector<int> &nums)
    {
        int total = 0;

        for (int n : nums)
        {
            total += n;

            preFix.push_back(total);
        }
    }

    int sumRange(int left, int right)
    {
        int preRight = preFix[right], preLeft = left > 0 ? preFix[left - 1] : 0;
        return preRight - preLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */