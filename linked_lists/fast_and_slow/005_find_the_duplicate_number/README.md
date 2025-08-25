# Find The Duplicate Number

- 🧩 Problem link: [Leetcode](https://leetcode.com/problemset/all/)
- 🚦 Difficulty: 🟡 Medium

> Similar problem to Linked List Cycle II [here](https://github.com/Shellyda/30-days-algorithms-challenge/blob/6f4ceb3ed66f549bbe740f7b4893ba3fc5da6c2f/linked_lists/fast_and_slow/004_linked_list_cycle_ii) but using arrays

## 💡 Approach

1. **Cycle detection**

   - Use two pointers:

     - `slow` moves one step: `slow = nums[slow]`.
     - `fast` moves two steps: `fast = nums[nums[fast]]`.

   - They will eventually meet inside the cycle because of the duplicate.

2. **Finding the cycle entrance (duplicate number)**

   - Initialize a new pointer `slow2` at the start (`index = 0`).
   - Move `slow` (from meeting point) and `slow2` (from start) one step at a time.
   - They will meet at the **duplicate number**, which corresponds to the cycle’s entry point.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        int slow2 = 0;
        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2)
                return slow;
        }
    }
};
```
