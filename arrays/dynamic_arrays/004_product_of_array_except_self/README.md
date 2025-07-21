# Product of Array Except self

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/product-of-array-except-self/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Left pass**:
   Create an array `left` where `left[i]` is the **product of all elements to the left of index `i`**.

2. **Right pass**:
   Traverse the array from right to left using a variable `right`, which keeps the **product of all elements to the right of index `i`**.

3. **Final result**:
   Multiply `left[i] * right` to get the final result for each position.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n) space for the output array and O(1) for extra space

## ✅ Solution

```cpp
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left(nums.size()), res(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            left[i] = i - 1 < 0 ? 1 : left[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int j = left.size() - 1; j >= 0; --j)
        {
            res[j] = left[j] * right;
            right *= nums[j];
        }

        return res;
    }
};
```
