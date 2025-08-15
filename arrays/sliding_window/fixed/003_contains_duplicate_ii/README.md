# Contains duplicate II

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/contains-duplicate-ii/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach 01 - Brute force

- Loop over each index `L`.
- For each `L`, loop over `R` from `L + 1` up to `min(size, L + k)` (only check within `k` positions ahead).
- If `nums[L] == nums[R]`, return `true`.
- If no duplicates are found in any window, return `false`.

## 🕒 Time and Space Complexity

- Time: O(n\*min(n,k))
- Space: O(1)

> Where `n` is the size of the arrays `nums` and `k` is the maximum distance between two equal numbers.

## ✅ Solution

```cpp
bool closeDuplicatesBruteForce(vector<int> &nums, int k)
{
    int size = static_cast<int>(nums.size());
    for (int L = 0; L < size; L++)
    {
        for (int R = L + 1; R < min(size, L + k); R++)
        {
            if (nums[L] == nums[R])
            {
                return true;
            }
        }
    }
    return false;
}
```

## 💡 Approach 02 - Sliding window

- `window` stores the elements currently in the window of size at most `k`.
- `l` is the left pointer of the window, `r` is the right pointer (loop index).
- If the window size exceeds `k` (`r - l > k`), remove the leftmost element and move `l` forward.
- Before inserting the current number `nums[r]`, check if it already exists in the set — if yes, return `true` (duplicate found within range).
- If not, insert it and keep moving.
- If the loop finishes without finding duplicates, return `false`.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(min(n,k))

> Where `n` is the size of the arrays `nums` and `k` is the maximum distance between two equal numbers.

## ✅ Solution

```cpp
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window;
        int l = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (r - l > k)
            {
                window.erase(nums[l]);
                l++;
            }
            if (window.count(nums[r]) > 0)
            {
                return true;
            }
            window.insert(nums[r]);
        }
        return false;
    }
};
```
