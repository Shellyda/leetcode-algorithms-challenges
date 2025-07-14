# Combinantion Sum

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/combination-sum/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Recursive DFS** explores all combinations of numbers from the array `nums` that add up to the given `target`.

2. At each step, you decide:

   - **Include** the current number (`nums[i]`) and call `dfs` again with `target - nums[i]`.

     - You keep `i` the same because you can **reuse the same number**.

   - **Exclude** the current number and move to the next one (`i + 1`).

3. Base cases:

   - If `target == 0`, you found a valid combination → add it to `res`.
   - If `i >= nums.size()` or `target < 0`, stop recursion (invalid path).

---

For `nums = [2,3,6,7]` and `target = 7`, valid combinations might be:

- `[2,2,3]`
- `[7]`

---

- It explores **all combinations** using DFS.
- Backtracking is done using `curr.pop_back()` to remove the last added element and try other paths.

## 🕒 Time and Space Complexity

- Time: O(2^(T/m))
- Space: O(2^(T/m))

> Where `t` is the given target and `m` is the minimum value in nums

## ✅ Solution

```cpp
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<int> curr;

        dfs(nums, target, curr, 0);

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
        curr.pop_back();                // backtracking - pop the number we just added
        dfs(nums, target, curr, i + 1); // run dfs without the number
    }
};
```
