#include <vector>
using std::vector;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int counter[] = {0, 0, 0};

        for (int n : nums)
        {
            counter[n]++;
        }

        int i = 0;
        for (int n = 0; n < 3; n++)
        {
            for (int j = 0; j < counter[n]; j++)
            {
                nums[i] = n;
                i++;
            }
        }
    }
};