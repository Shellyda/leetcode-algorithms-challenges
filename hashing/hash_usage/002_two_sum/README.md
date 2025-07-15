# Two Sum

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/two-sum/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- **Initialize a hash map** (`indices`) to store each number and its corresponding index.
- **First loop** through the array:

  - Store each number as a key and its index as the value in the hash map.

- **Second loop** through the array:

  - For each number, compute the **complement** (`target - current number`).
  - Check if the complement exists in the hash map **and** is not the same index as the current number.
  - If so, return the pair of indices: current index and the index of the complement.

- If no such pair is found after both loops, return an empty vector.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices; // val -> index

        for (int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            // check if number exists in hashmap and if is not equal to curr
            if (indices.count(diff) && indices[diff] != i)
            {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};
```
