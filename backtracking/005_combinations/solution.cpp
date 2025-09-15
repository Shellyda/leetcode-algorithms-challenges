#include <vector>
using std::vector;

// Given n numbers (1 - n), return all possible combinations
// of size k. (n choose k math problem).
// Time: O(k * 2^n)
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> currComb;

        dfs(1, currComb, res, n, k);

        return res;
    }

private:
    void dfs(int index, vector<int> &currComb, vector<vector<int>> &res, int n,
             int k)
    {
        if (currComb.size() == k)
        {
            res.push_back(currComb);
            return;
        }

        if (index > n)
            return;

        currComb.push_back(index);
        dfs(index + 1, currComb, res, n, k);

        currComb.pop_back();
        dfs(index + 1, currComb, res, n, k);
    }
};