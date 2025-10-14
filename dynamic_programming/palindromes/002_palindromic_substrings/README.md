# Palindromic Substrings

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/palindromic-substrings/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- This solution uses the expand-around-center approach to find all palindromic substrings.
- For each character (and each gap between characters), it expands outwards as long as the substring remains a palindrome.
- The helper function is called twice: once for odd-length palindromes (centered at a character) and once for even-length palindromes (centered between characters).

## 🕒 Time and Space Complexity

- Time Complexity: O(n^2), where n is the length of the string, since each center can expand up to n times.
- Space Complexity: O(1), as no extra space proportional to input size is used.

## ✅ Solution

```cpp
class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;

        helper(0, count, s);
        helper(1, count, s);

        return count;
    }

    void helper(int rightStart, int &count, string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i + rightStart;

            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                count++;
                l--;
                r++;
            }
        }
    }
};
```
