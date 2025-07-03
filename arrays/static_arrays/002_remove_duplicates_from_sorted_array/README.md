# Remove Duplicates From Sorted Array

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

```cpp
left pointer = 0 -> l
Right pointer = 1 -> r

for r = 1 to length of nums
    if nums[r-1] != nums[l]
        l++
        nums[l] = nums[i]
```

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
 int removeDuplicates(vector<int> &nums)
    {
        int left = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[left])
            {
                left++;
                nums[left] = nums[i];
            }
        }

        return left + 1;
    }
```
