# Sort Colors

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/sort-colors/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Note the dataset to be sorted has values within a specific range

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int counter[] = {0, 0, 0};

        for (int n : nums)
        {
            counter[n]++;
        }

        int i = 0;
        for (int n = 0; n < 3; n++)
        {
            for (int j = 0; j < counter[n]; j++)
            {
                nums[i] = n;
                i++;
            }
        }
    }
};
```
