# Maximum Sum Circular Subarray

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/maximum-sum-circular-subarray/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **`globalMax`**: The maximum subarray sum using the standard Kadane’s algorithm.
2. **`globalMin`**: The minimum subarray sum using a similar approach.
3. **`total`**: The sum of all elements in the array.

The maximum circular subarray sum can be either:

- The **non-circular maximum subarray** (`globalMax`), or
- The **circular subarray sum**, which is the total sum minus the minimum subarray sum (`total - globalMin`).

If all numbers are negative, the maximum subarray is just the maximum single element (`globalMax`).

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int globalMax = nums[0], globalMin = nums[0];
        int currMax = 0, currMin = 0, total = 0;

        for (int n : nums)
        {
            currMax = max(currMax + n, n);
            currMin = min(currMin + n, n);
            total += n;

            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }

        return globalMax > 0 ? max(globalMax, total - globalMin) : globalMax;
    }
};
```
