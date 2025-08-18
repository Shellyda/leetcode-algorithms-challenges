# Two Sum II input array is sorted

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

1. Start with `l` at the leftmost index and `r` at the rightmost.
2. Compute `curResult = numbers[l] + numbers[r]`.
3. If `curResult < target`, move `l++` (need a bigger sum).
4. If `curResult > target`, move `r--` (need a smaller sum).
5. If equal, return the indices (1-based).

- If no pair is found, return an empty vector.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/b13efdb3-c268-45ac-fdd4-13ead6600600/sharpen=1)

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;

        while (l < r)
        {
            int curResult = numbers[l] + numbers[r];
            if (curResult < target)
                l++;
            else if (curResult > target)
                r--;
            else
                return {l + 1, r + 1};
        }

        return {};
    }
};
```
