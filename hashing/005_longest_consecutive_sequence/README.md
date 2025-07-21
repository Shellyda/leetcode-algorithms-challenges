# Longest Consecutive Sequence

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/longest-consecutive-sequence/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. **Convert to HashSet**
   Store all numbers in an `unordered_set` for O(1) lookup time.

2. **Iterate Through Set**
   For each number `num` in the set:

   - **Start of Sequence Check**
     Only begin counting if `num - 1` is **not** in the set (i.e., it's the start of a sequence).

3. **Count Consecutive Sequence**

   - Initialize a `streak` counter.
   - While `num + streak` exists in the set, increment the streak.

4. **Update Longest Streak**

   - Update the result with the maximum of the current longest and the new streak.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet)
        {
            if (!numSet.count(num - 1))
            {
                int streak = 1;
                while (numSet.count(num + streak))
                {
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
```
