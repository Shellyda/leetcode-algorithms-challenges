# Subsets

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/subsets/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. Use DFS (depth-first search) to explore all possible subsets of `nums`.

2. At each index `i`, make **two decisions**:

   - **Include** `nums[i]` in the current subset.
   - **Do not include** `nums[i]` (backtrack).

3. When you reach the end of the array (`i >= nums.size()`), store the current subset in the result.

---

- `subset.push_back(nums[i])` explores the path where the current element is included.
- `subset.pop_back()` undoes that choice to explore the path where it’s excluded.
- This builds a **decision tree** with all combinations.

---

For `nums = [1, 2]`, it explores:

```
[]
[2]
[1]
[1,2]
```

Result: `[[], [2], [1], [1, 2]]`

## 🕒 Time and Space Complexity

- Time: O(n\*((2)^n))
- Space: O(n) extra space, O(2^n) for the output list

## ✅ Solution

```cpp
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
```
