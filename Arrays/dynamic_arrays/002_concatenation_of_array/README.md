# Concatenation of Array

- 🧩 Problem link: [Leetcode](https://leetcode.com/problemset/all/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Resize array, doubling it and then add the elements again

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans;
        ans = nums;
        ans.resize(nums.size() * 2);

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i + nums.size()] = nums[i];
        }

        return ans;
    }
```
