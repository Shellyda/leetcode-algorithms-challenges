# Counting Bits

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/counting-bits)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Bit Mask
- Use AND operation Table of truth and Bit Shifting concepts

## 🕒 Time and Space Complexity

- Time: O(nlogn)
- Space: O(1) extra space, O(n) space for the output array

## ✅ Solution

```cpp
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result;
        for (int num = 0; num <= n; num++)
        {
            int currCount = countHelper(num);

            result.push_back(currCount);
        }

        return result;
    }

private:
    int countHelper(int num)
    {
        int count = 0;

        while (num > 0)
        {
            if ((num & 1))
                count++;
            num = num >> 1; // shift right - diving the given integer by 2 - halving
        }

        return count;
    }
};
```
