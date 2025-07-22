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
