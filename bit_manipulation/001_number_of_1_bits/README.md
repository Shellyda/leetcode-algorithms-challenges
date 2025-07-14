# Number of 1 Bits

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/number-of-1-bits)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Bit Mask
- Use AND operation Table of truth and Bit Shifting concepts

## 🕒 Time and Space Complexity

- Time: O(1)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return countBits(n);
    }

private:
    int countBits(uint32_t n)
    {
        int count = 0;

        while (n > 0)
        {
            if ((n & 1))
                count++;
            n = n >> 1; // shift right - diving the given integer by 2 - halving
        }

        return count;
    }
};
```
