#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;

        while (l < r)
        {
            int curResult = numbers[l] + numbers[r];
            if (curResult < target)
                l++;
            else if (curResult > target)
                r--;
            else
                return {l + 1, r + 1};
        }

        return {};
    }
};