# Group Anagrams

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/group-anagrams/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach 01 - Brute force

- Iterate through each string in the list.
- For each string:

  - Create a temporary list (`subList`) to store its anagram group.
  - Compare it with all remaining strings using the `areAnagrams` function.
  - If an anagram is found:

    - Add it to `subList`.
    - Remove it from the original list to avoid reprocessing.

- Add each `subList` to the final result (`groups`).

---

`areAnagrams(str1, str2)`:

- Compares two strings by building a **character frequency map** for each.
- Returns true if the two maps are equal (i.e., strings are anagrams).

## 🕒 Time and Space Complexity

- Time: O(n^3 + (n^2)\*L)
- Space: O(n\*L)

> Where `n` is the number of strings and `L` is the length of the longest string

## ✅ Solution 01

```cpp
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> groups;
        for (int i = 0; i < strs.size(); i++)
        {
            int left = i, right = strs.size() - 1;
            vector<string> subList;
            subList.push_back(strs[left]);
            while (left < right)
            {
                if (areAnagrams(strs[left], strs[right]))
                {
                    subList.push_back(strs[right]);
                    strs.erase(strs.begin() + right);
                }

                right--;
            }
            groups.push_back(subList);
        }

        return groups;
    }

private:
    bool areAnagrams(string str1, string str2)
    {
        if (str1.size() != str2.size())
            return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < str1.size(); i++)
        {
            map1[str1[i]]++;
            map2[str2[i]]++;
        }

        return map1 == map2;
    }
};
```

## 💡 Approach 02 - Hash Map

- Use a **hash map** to group strings by their character frequency pattern.
- For each string:

  - Create a **count array of size 26** to count occurrences of each letter (`a` to `z`).
  - Convert this count array into a **comma-separated string key**.
  - Use the key to group anagrams in the hash map.

- Finally, collect all grouped anagram lists from the hash map into the result.

## 🕒 Time and Space Complexity

- Time: O(n\*L)
- Space: O(n\*L)

> Where `n` is the number of strings and `L` is the length of the longest string

## ✅ Solution 02

```cpp
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hashMap;

        for (const auto &s : strs)
        {                             // ['nat', 'tat']
            vector<int> count(26, 0); // [0,0,...0] -> a...z

            for (char c : s)
            { // map 'a' to index 0, map 'b' to index 1.... map 'z' to index 26
                // c -> 'n' - 'a' values
                count[c - 'a']++;
            }

            /*
              a -> 80, 80 - 80 = 0
              b -> 81, 81 - 80 = 1
              ...
            */

            // setting key to count letters pattern
            string key = to_string(count[0]);

            for (int i = 1; i < 26; ++i)
            {
                key += ',' + to_string(count[i]);
                // counting char which happen to be in string
                // 1 -> 1xa
                // 1, 0, 1 -> 1xa, 0xb, 1xc
                // 1, 0, 1, 0 ...
                //...
            }

            hashMap[key].push_back(s); // -> key = "1,0,1,0,2" -> push `acee`
        }

        vector<vector<string>> res;

        for (const auto &pair : hashMap)
        {

            res.push_back(pair.second);
        }

        return res;
    }
};
```
