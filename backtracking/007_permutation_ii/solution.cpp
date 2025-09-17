#include <vector>
#include <set>
using std::set;
using std::vector;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        return dfs(0, nums);
    }

private:
    vector<vector<int>> dfs(int i, vector<int> &nums)
    {
        if (i >= nums.size())
            return {{}};

        vector<vector<int>> resPerms, perms;

        perms = dfs(i + 1, nums);

        for (vector<int> p : perms)
        {
            for (int j = 0; j < p.size() + 1; j++)
            {
                vector<int> pCopy(p);
                pCopy.insert(pCopy.begin() + j, nums[i]);
                resPerms.push_back(pCopy);
            }
        }

        set<vector<int>> result(resPerms.begin(), resPerms.end());

        return vector<vector<int>>(result.begin(), result.end());
    }
};