# Remove Element

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/remove-element/)
- 🚦 Difficulty: easy

## 💡 Approach

```cpp
left pointer = 0 -> l
Right pointer = 0 -> r

for r = 0 to length of nums
    if nums[r] != val
        nums[l] = nums[r]
        l++
```

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
int removeElement(vector<int> &nums, int val)
    {
        int l = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] != val)
            {
                nums[l] = nums[r];
                l++;
            }
        }

        return l;
    }
```
