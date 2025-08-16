# Minimum Size Subarray Sum

- 🧩 Problem link: [Leetcode](https://leetcode.com/problemset/all/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. Expand the right pointer `r` and add `nums[r]` to `total`.
2. While the window sum `total` is ≥ `target`:

   - Update the minimum length `len` with the current window size `(r - l + 1)`.
   - Shrink the window from the left by subtracting `nums[l]` and moving `l` forward.

- At the end, return `len` if updated, otherwise return `0` (no subarray found).

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/3a95351b-f81b-44fe-dfd8-f8af68b78d00/sharpen=1)

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, total = 0, len = INT_MAX;

        for (int r = 0; r < nums.size(); r++)
        {
            total += nums[r];

            while (total >= target)
            {
                len = min(len, r - l + 1);
                total -= nums[l];
                l++;
            }
        }

        return len != INT_MAX ? len : 0;
    }
};
```
