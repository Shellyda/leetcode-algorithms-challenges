# Range Sum Query - Immutable

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/range-sum-query-immutable/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. In the constructor, build `preFix` where `preFix[i]` = sum of `nums[0..i]`.
2. To compute the sum in `[left, right]`:
   - `preRight = preFix[right]` (sum from 0 até right).
   - `preLeft = preFix[left - 1]` if `left > 0`, otherwise 0.
   - Answer = `preRight - preLeft`.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/3d545c0b-3a8a-4650-9e6c-0efd56dac600/sharpen=1)

## 🕒 Time and Space Complexity

- Time: O(1)
- Space: O(n)

## ✅ Solution

```cpp
class NumArray
{
public:
    vector<int> preFix;
    NumArray(vector<int> &nums) // O(n) - builds prefix sum in a single pass
    {
        int total = 0;

        for (int n : nums)
        {
            total += n;

            preFix.push_back(total);
        }
    }

    int sumRange(int left, int right) // O(1)
    {
        int preRight = preFix[right], preLeft = left > 0 ? preFix[left - 1] : 0;
        return preRight - preLeft;
    }
};
```
