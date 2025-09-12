#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;

        // Sort the input arr to all duplicates become adjacent
        sort(nums.begin(), nums.end());

        vector<int> subset;

        dfs(nums, 0, subset, res);

        return res;
    }

private:
    void dfs(const vector<int> &nums, int i, vector<int> &subset,
             vector<vector<int>> &res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        // Decision to include the curr node
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res);

        // Decision to NOT include the curr node
        subset.pop_back();

        // Jump all duplicates
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;

        dfs(nums, i + 1, subset, res);
    }
};
