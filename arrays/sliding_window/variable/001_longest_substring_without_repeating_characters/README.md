# Longest Substring Without Repeating Characters

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/longest-substring-without-repeating-characters)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach 01 - Brute force

1. **Use a HashSet (`unordered_set<char>`)**

   - To track characters currently in the substring without duplicates.

2. **Loop through each character in the string (`for i = 0 to s.size()`)**

3. **If the character is not in the set:**

   - Add it to the set.
   - Increment the current streak (`streak++`).

4. **If the character is already in the set (duplicate found):**

   - Go backward from `i - 1` to find the previous occurrence of the character.
   - Set `i = j + 1` to restart the loop right after the duplicate.
   - Clear the set and insert the current character.
   - Reset streak to 1.

5. **Update the `longest` result on each iteration.**

## 🕒 Time and Space Complexity

- Time: O(n\*m),
- Space: O(min(n,m))

> Where `n` is the length of the string and `m` is the total number of unique characters in the string

## ✅ Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1) return 1;
        unordered_set<char> set;

        int longest = 0, streak = 0;

        for(int i = 0; i < s.size(); i++){
            if(!set.count(s[i])) {
                set.insert(s[i]);
                streak++;
            } else {
                int j = i-1;
                while(s[j] != s[i]){
                    j--;
                }

                i = j+1;

                set.clear();
                set.insert(s[i]);
                streak = 1;
            }
            longest = max(longest, streak);
        }

        return longest;
    }
};
```

## 💡 Approach 02 - Sliding Window

1. `r` expands the window to include the current character.
2. If `s[r]` is already in the window, move `l` forward (removing characters) until `s[r]` is no longer duplicated.
3. Insert `s[r]` into the set.
4. Update `len` as the maximum window size `(r - l + 1)`.

- After the loop, return the maximum length found.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(min(n,m))

> Where `n` is the length of the string and `m` is the total number of unique characters in the string

## ✅ Solution

```cpp
/*
 l = 0, len = INT_MIN
 window = set()
 for r in range(len(nums)):
    while(window.count(nums[r]) > 0){
        window.erase(nums[l]);
        l++;
    }
    window.insert(nums[r]);
    len = max(r - l + 1, len)
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 1)
            return 1;

        int l = 0, len = INT_MIN;
        unordered_set<char> window;

        for (int r = 0; r < s.size(); r++)
        {
            while (window.count(s[r]) > 0)
            {
                window.erase(s[l]);
                l++;
            }

            window.insert(s[r]);
            len = max(r - l + 1, len);
        }

        return len != INT_MIN ? len : 0;
    }
};
```
