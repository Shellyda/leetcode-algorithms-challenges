
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;

        vector<int> subset;

        dfs(nums, 0, subset, res);

        return res;
    }

private:
    void dfs(const vector<int> &nums, int i, vector<int> &subset, vector<vector<int>> &res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        // Will go to both sides of decision tree

        // Decision to include the curr node
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res);

        // Decision to NOT include the curr node
        subset.pop_back();
        // subset = []
        dfs(nums, i + 1, subset, res);
    }
};
