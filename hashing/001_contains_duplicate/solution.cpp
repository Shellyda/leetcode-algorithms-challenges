#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> countMap;

        for (int n : nums)
        {
            if (countMap.count(n) == 0)
            {
                countMap[n] = 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};