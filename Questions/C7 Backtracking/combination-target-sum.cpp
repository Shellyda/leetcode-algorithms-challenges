#include <vector>
using std::vector;

// O(2^T/m) -> T is the target given and m is the min value in the given array

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<int> curr;

        // ex: [2,3,6,9]
        dfs(nums, target, curr, 0); // backtracking

        return res;
    }

private:
    void dfs(vector<int> &nums, int target, vector<int> &curr, int i)
    {
        if (i >= nums.size() || target < 0)
            return;

        if (target == 0)
        {
            res.push_back(curr);
            return;
        }

        // Decision to NOT change the curr number
        curr.push_back(nums[i]);
        dfs(nums, target - nums[i], curr, i); // all combinations with the number

        // Decision to NOT continuos with the curr number
        curr.pop_back();                // pop the number we just added
        dfs(nums, target, curr, i + 1); // run dfs without the number
    }
};
