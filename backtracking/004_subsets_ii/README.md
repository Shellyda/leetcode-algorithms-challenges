# Subsets II

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/subsets-ii/description/)
- 🚦 Difficulty: 🟡 Medium

## Concept and Approach

**Combinatorics** is a branch of discrete mathematics that concerns itself with permutations, subsets and combinations. As a matter of fact, graphs, are also a branch of combinatorics.

### Subsets

Formally, in mathematics, if we have two sets, Set A and Set B, Set A is a subset to Set B if all of its elements are found in Set B.

Additionally, any set is a subset of itself and an empty set is a subset of every set. Order is not important in subsets, but the elements within a set must be distinct.

For example, suppose we are given `Set A = {1,2,3,4,5}` and `Set B = {5,2,1}`. `Set B` is a subset of `Set A` because it only contain elements that can be found in `Set A`.

Changing the order of `Set B` to `{2,5,1}` does not change the set itself, so it is still a subset of `Set A`.

Given `Set C = {9,10,11,12}` and `Set D = {6, 9, 10}`, `Set D` is not a subset of `Set C` because it contains a
6, which `Set C` does not have.

#### Distinct elements

> Q: Given a list of distinct nums, return all possible distinct subsets.

Recall from backtracking that once we make a choice to go down a path, we backtrack and explore other choices. Applying this concept to subsets would mean that for each element, we explore all the subsets that include that element. We then backtrack to explore all the subsets that don't include that element. We do this until we exhaust all the elements and by the end, we will have ended up with all possible distinct subsets.

Given `nums = {1,2,3}`, the following visual demonstrates all possible distinct subsets.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/b7217b06-0aae-4cac-69bf-0467fcfb7300/sharpen=1)

In the implementation, we have two functions: `subsetsWithoutDuplicates` and `helper`.

If the list we have been given does not contain duplicates, we will implement the function `subsetsWithoutDuplicates`. In this method, we will declare a list of lists `subsets` and another list `currSet`. Once we build each `currSet`, we will add it to `subsets`.

To build each `currSet`, we will need a `helper` method.

```cpp
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

vector<vector<int>> subsetsWithoutDuplicates(vector<int>& nums) {
    vector<int> curSet;
    vector<vector<int>> subsets;
    helper(0, nums, curSet, subsets);
    return subsets;
}
```

We will pass in an initial index `i`, `nums`, which is our list, `currSet` and `subsets` to the `helper` function. We will then iterate through the entire list, append the current number in `nums` and apply our standard backtracking algorithm, i.e. recurse until we hit the base case and then `pop` from `currSet` so that we can go down the path where we decide to not include the current element.

```cpp
void helper(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& subsets) {
    if (i >= nums.size()) {
        subsets.push_back(vector<int>(curSet));
        return;
    }
    // decision to include nums[i]
    curSet.push_back(nums[i]);
    helper(i + 1, nums, curSet, subsets);
    curSet.pop_back();

    // decision NOT to include nums[i]
    helper(i + 1, nums, curSet, subsets);
}
```

The visuals below demonstrate the full step-by-step implementation to derive subsets from the list `[1,2,3]`. The white array below each step represents `subsets`. The blue arrays in the decision tree represent the current subset being processed, `curSet`.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/74fca3fa-4ecb-4ae4-9e6b-67eaf26eca00/sharpen=1)

![img2](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/dec05d7e-1dcd-4526-4a04-4748869f1000/sharpen=1)

#### Non-distinct elements

> Q: Given a list of nums that are not necessarily distinct, return all possible distinct subsets.

In this problem, we are given a `nums` that contain duplicates. To create concrete subsets, we first sort the array so all duplicates are adjacent to one another. We can then run a while loop to skip over the duplicates. This is different than the previous problem because in this case, when we backtrack, i.e. pop from the `curSet`, we run a while loop to skip over the duplicates before calling `helper2` again. We also make sure that our `i` pointer does not go out of bounds.

This is the difference between `helper` and `helper2`.

Below is the implementation.

```cpp
vector<vector<int>> subsetsWithDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> curSet;
    vector<vector<int>> subsets;
    helper2(0, nums, curSet, subsets);
    return subsets;
}

void helper2(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& subsets) {
    if (i >= nums.size()) {
        subsets.push_back(vector<int>(curSet));
        return;
    }

    // decision to include nums[i]
    curSet.push_back(nums[i]);
    helper2(i + 1, nums, curSet, subsets);
    curSet.pop_back();

    // decision NOT to include nums[i]
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
    }
    helper2(i + 1, nums, curSet, subsets);
}
```

## 🕒 Time and Space Complexity

We build a recursive decision tree to explore all possible subsets. For every decision we can make, we can either include or not include the current element. This results in a branching factor of `2` and a height of `n`.

Thus, there are roughly `2^n` possible subsets. For each subset we create a copy of it before adding it to the final list of subsets. The max length a subset could be is proportional to the length of the input list `nums` which is `n`.

Thus, the overall time complexity is O(n∗2^n).

- Time: O(n∗2^n)
- Space: O(n)

If we are not including the space needed to store the final list of subsets, the space complexity is O(n).

This is because we are using recursion and the space needed to store the current subset is proportional to the length of the input list nums.

## ✅ Solution

```cpp
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
```
