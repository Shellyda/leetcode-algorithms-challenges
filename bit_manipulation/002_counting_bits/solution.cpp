#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result;
        for (int num = 0; num <= n; num++)
        {
            int currCount = countHelper(num);

            result.push_back(currCount);
        }

        return result;
    }

private:
    int countHelper(int num)
    {
        int count = 0;

        while (num > 0)
        {
            if ((num & 1))
                count++;
            num = num >> 1; // shift right - diving the given integer by 2 - halving
        }

        return count;
    }
};
