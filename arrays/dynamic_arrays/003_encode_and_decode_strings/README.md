# Encode and Decode Strings

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/encode-and-decode-strings/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

#### **Encode**

1. For each string in the list:

   - Add its **length**, followed by a special delimiter (e.g., `#`), then the string itself.

2. Concatenate all of them into one encoded string.

**Example:**

```text
["hello", "world"] → "5#hello5#world"
```

#### **Decode**

1. Iterate through the encoded string:

   - Read the number before `#` → this gives the length of the next string.
   - Extract the string using this length.

2. Repeat until the end of the encoded string.

**Example:**

```text
"5#hello5#world" → ["hello", "world"]
```

## 🕒 Time and Space Complexity

- Time: O(m) for each encode() and decode() function calls.
- Space: O(m+n) for each encode() and decode() function calls.

> Where `m` is the sum of lengths of all the strings and `n` is the number of strings.

## ✅ Solution

```cpp
class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encoded;
        for (string &str : strs)
        {
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int i = 0;

        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }

        return result;
    }
};
```
