# Reverse Bits

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/reverse-bits/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- OR operation and shifting concepts

1. Initialize a `result` variable to `0`.

   - This will store the reversed bits.

2. Loop 32 times (for all bits in a 32-bit integer):

   - Shift the `result` left by `1` to make space for the next bit.

   - Take the least significant bit of `n` using `n & 1`.

   - Add that bit to the `result` using `result |= n & 1`.

3. Shift `n` right by `1` to process the next bit.

## 🕒 Time and Space Complexity

- Time: O(1)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++)
        {
            result <<= 1;    // shift result to the left
            result |= n & 1; // add the last bit of n to result
            n >>= 1;         // shift n to the right
        }

        return result;
    }
};
```
