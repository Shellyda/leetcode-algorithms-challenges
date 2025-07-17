# Valid Palindrome

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/valid-palindrome/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

1. **Edge Case Check**:
   If the string length is 0 or 1, return `true` (trivially a palindrome).

2. **Filter Input**:

   - Loop through each character in the string.
   - Keep only **alphanumeric** characters.
   - Convert them to **lowercase** and append to a new string `filtered`.

3. **Two-Pointer Comparison**:

   - Initialize two pointers: `l` at the start and `r` at the end of `filtered`.
   - While `l < r`, compare characters at both ends:

     - If they differ, return `false` (not a palindrome).
     - Else, move both pointers inward.

4. **Return Result**:

   - If the loop completes without mismatch, return `true` (it's a palindrome).

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.size() <= 1)
            return true;

        string filtered;

        for (char c : s)
        {
            if (isalnum(c))
            {
                filtered += tolower(c);
            }
        }

        int l = 0, r = filtered.size() - 1;

        while (l < r)
        {
            if (filtered[l] != filtered[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};
```
