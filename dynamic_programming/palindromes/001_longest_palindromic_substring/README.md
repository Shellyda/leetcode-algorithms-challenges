# Longest Palindromic Substring

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/longest-palindromic-substring/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

Surprisingly, palindrome problems can also be solved with dynamic programming. Although the pattern by which they are solved is not the typical DFS/memoization/bottom-up approach.

> Q: Given a string S, return the length of the longest palindromic substring within S.

A palindrome is a sequence of characters that read the same backwards as forwards. Think "racecar", or "aba". So, by definition, a palindromic substring is a contiguous part of a string that is a palindrome.

We can use to determine whether a string is a palindrome the two pointers approach. However, here we are faced with a variation, i.e. finding the length of the longest palindromic substring

### Brute force Approach

The brute force way of approaching this is to go through every possible substring and determine if it is a palindrome using the two-pointer approach. If \(n\) is the number of characters in our string, and the number of substrings that each character can form increases in a linear fashion to \(n\), we will have \(n^2\) substrings in total. Then, given these \(n^2\) substrings, and the longest substring being of length \(n\), the total time complexity comes to \(O(n^3)\).

### DP Approach

If we compare the first and the last character and they are equal, the sub-problem is the determining whether the inner string, excluding the characters at index `0` and `length - 1`, is a palindrome. If the inner string is a palindrome and so are the outer-most characters, we know the entire substring is a palindrome.

Dynamic programming approach to this problem tells us that we should solve a sub-problem first, and then expand out. Given the string `s = 'abaab'`, we can start from the middle and expand outwards. However, this will only give us palindromic substrings with `a` as the middle character. This does not guarantee that we will get the longest palindromic substring, and in the case of `s`, this approach fails because the longest palindromic substring is `baab` which is not formed by expanding out from `a`, at the 2nd index.

> The visual below shows all the substrings where a at index 2 is the middle character.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/6a202ae9-0a60-475e-2cc0-bf7cddd5b800/sharpen=1)

Since it is not guaranteed that picking the middle character will produce the longest palindromic substring, the only way is pick each character, and expand out using a left and a right pointer. To do this, we can run a for loop over our string, and for each iteration, set the left and the right pointer starting position to the current character. Then, as long as our left and right are not out of bounds, and the character at left matches character at right, we can decrement left and increment right (this is the expanding out part). We can then take the difference of our left and right pointer and add 1 to be inclusive of all elements. This is shown in the visual and the code below:

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/1ab6c964-43d9-448f-6739-5426a11f8d00/sharpen=1)

```cpp
#include <string>
#include <algorithm>

using std::max;
using std::string;

// Time: O(n^2), Space: O(n)
int longest(string& s) {
    int length = 0;

    for (int i = 0; i < s.size(); i++) {
        // odd length
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if ((r - l + 1) > length) {
                length = r - l + 1;
            }
            l--;
            r++;
        }
    }
    return length;
}
```

Do you notice a slight error though? The longest palindromic substring is of length 3 but we can clearly see that is should be `baab` - length 4, which our algorithm failed to account for. You might have also noticed that all our palindromes above are of odd length. This is because our starting substring is of length 1 and when we expand from left and right, we are adding 2 to our length. Of course, sum of an even and odd number is always odd, which results in giving us the longest palindromic substring of odd length.

### Even length substrings

To ensure we get the longest palindromic substring, whether even or odd, we need to start with an initial substring of even length. This way, we will have taken into account substrings with even lengths as well. To calculate the longest palindromic substring, we can return max(odd, even). In the visual below, we start with ab and try to expand outwards. Since ab is not a palindrome, we will never enter the while loop. When we get to aa, expanding outwards will give us baab before our right pointer goes out of bounds. This is the longest palindromic substring of length 4.

![img](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/4fe914de-c9b0-438f-7038-6bf854e92600/sharpen=1)

```cpp
// Time: O(n^2), Space: O(n)
int longest(string& s) {
    int length = 0;

    for (int i = 0; i < s.size(); i++) {
        // odd length
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if ((r - l + 1) > length) {
                length = r - l + 1;
            }
            l--;
            r++;
        }
        // even length
        l = i, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if ((r - l + 1) > length) {
                length = r - l + 1;
            }
            l--;
            r++;
        }
    }
    return length;
}
```

## 🕒 Time and Space Complexity

The dynamic programming solution brings our \(O(n^3)\) time complexity to \(O(n^2)\) because we have \(n\) characters and to form a substring from each character is also \(n\).

## ✅ Solution

```cpp
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int length = 0, resIdx = 0;
        // odd sizes
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                if (r - l + 1 > length)
                {
                    resIdx = l;
                    length = r - l + 1;
                }
                l--;
                r++;
            }
        }

        // even sizes
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                if (r - l + 1 > length)
                {
                    resIdx = l;
                    length = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(resIdx, length);
    }
};
```

The refactored version of the code has been added for the sake of completeness as it strives to save writing duplicate code.

```cpp
// Same solution, without duplicate code.
// Time: O(n^2), Space: O(n)
int longest(string& s) {
    int length = 0;
    for (int i = 0; i < s.size(); i++) {
        // odd length
        length = max(length, helper(s, i, i));

        // even length
        length = max(length, helper(s, i, i + 1));
    }
    return length;
}

int helper(string& s, int l, int r) {
    int maxLength = 0;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        if ((r - l + 1) > maxLength) {
            maxLength = r - l + 1;
        }
        l--;
        r++;
    }
    return maxLength;
}
```
