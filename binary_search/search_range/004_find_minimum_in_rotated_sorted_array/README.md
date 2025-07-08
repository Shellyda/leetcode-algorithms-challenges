# Find Minimum in rotated sorted array

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- I thought in the concept of rotating the array which moves the elements in right to left and vice-versa
- So we are looking for one number that is in the right side
- The idea was move the `r` pointer to `mid` index when `nums[m] < nums[r]` and if is not move `l` pointer to `mid+1` index

## 🕒 Time and Space Complexity

- Time: O(logn)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return nums[l];
    }
};
```
