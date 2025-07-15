#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices; // val -> index

        for (int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            // check if number exists in hashmap and if is not equal to curr
            if (indices.count(diff) && indices[diff] != i)
            {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};