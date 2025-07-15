# Contains Duplicate

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/contains-duplicate/description/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. Use an **unordered map** (`countMap`) to track whether a number has already been seen.

2. For each number in the input array:

   - If it's **not in the map**, add it.
   - If it **already exists in the map**, return `true` (duplicate found).

3. If you finish the loop without returning, then there are **no duplicates** → return `false`.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> countMap;

        for (int n : nums)
        {
            if (countMap.count(n) == 0)
            {
                countMap[n] = 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
```
