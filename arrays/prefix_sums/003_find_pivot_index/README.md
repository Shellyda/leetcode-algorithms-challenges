# Find pivot index

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/find-pivot-index/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. First, build a prefix sum (`preF`) where each entry stores the cumulative sum up to that index.
2. For each index `i`, compute:

   - **left sum** → sum from `0` to `i-1` using `sumRange`.
   - **right sum** → sum from `i+1` to `n-1` using `sumRange`.

3. If `left sum == right sum`, then `i` is the pivot index and is returned.
4. If no index satisfies the condition, return `-1`.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    vector<int> preF;

    int pivotIndex(vector<int> &nums)
    {
        preF.clear();
        preF.reserve(nums.size());

        int total = 0;
        for (int n : nums)
        {
            total += n;
            preF.push_back(total);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int leftSum = sumRange(0, i - 1);
            int rightSum = sumRange(i + 1, nums.size() - 1);
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }

private:
    int sumRange(int left, int right)
    {
        if (right < left)
            return 0;
        int preRight = (right >= 0) ? preF[right] : 0;
        int preLeft = (left > 0) ? preF[left - 1] : 0;
        return preRight - preLeft;
    }
};
```
