#include <unordered_set>
#include <vector>
using namespace std;

// Same problem using sliding window.

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window;
        int l = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (r - l > k)
            {
                window.erase(nums[l]);
                l++;
            }
            if (window.count(nums[r]) > 0)
            {
                return true;
            }
            window.insert(nums[r]);
        }
        return false;
    }
};