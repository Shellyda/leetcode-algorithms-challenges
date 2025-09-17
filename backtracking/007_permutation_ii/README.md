# Permutation II

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/permutations-ii/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- It applies a **depth-first search (DFS)** starting from index `i`.
- The base case is when `i` reaches the end of the array: it returns an empty permutation (`{}`).
- From there, each recursive call gets all permutations of the suffix `nums[i+1 ... end]`.
- For every smaller permutation, it **inserts `nums[i]` into every possible position**, creating new permutations.
- Since inserting the same number multiple times may produce duplicates (e.g., with repeated values), the algorithm stores the results in a **set of vectors**, which automatically removes duplicates.
- Finally, the set is converted back into a vector of vectors and returned.

In short: the algorithm **constructs permutations by recursive insertion** and **ensures uniqueness via a set**.

## 🕒 Time and Space Complexity

- Time: O(n\*n!)
- Space: O(n\*n!)

## ✅ Solution

```cpp
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
```
