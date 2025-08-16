# Longest Repeating Character Replacement

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/longest-repeating-character-replacement/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Goal: find the length of the longest substring where you can replace at most `k` characters to make all letters the same.
- Sliding window approach with a hash map (`count`) to track character frequencies.
- For each character at position `r`:

  1. Increment its frequency.
  2. Update `maxFreq` (the count of the most frequent char seen in the window).
  3. If the window size `(r - l + 1)` minus `maxFreq` > `k`, it means too many replacements would be required → shrink window from the left (`l++`).
  4. Otherwise, keep expanding and update `len` with the current valid window size.

- At the end, `len` holds the longest valid substring length.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(m)

> Where `n` is the length of the string and `m` is the total number of unique characters in the string

## ✅ Solution

```cpp
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> count;
        int len = 0, l = 0, maxFreq = 0;

        for (int r = 0; r < s.size(); r++)
        {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            while ((r - l + 1) - maxFreq > k)
            {
                count[s[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
        }

        return len;
    }
};
```
