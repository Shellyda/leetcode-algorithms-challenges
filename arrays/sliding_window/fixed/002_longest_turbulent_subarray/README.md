# Longest turbulent subarray

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/longest-turbulent-subarray/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- Two pointers, `l` and `r`, track the current subarray’s start and end.
- `prevSign` keeps track of the previous comparison sign (`">"` or `"<"`).
- Iterate through the array with `r`:

  - If the current pair alternates sign compared to `prevSign` (e.g., previously `">"`, now `"<"` or vice versa), extend the subarray and update `maxLen`.
  - If the signs don’t alternate or are equal, reset the start `l` to just before `r` and clear `prevSign` to start a new subarray.

- Finally, return the maximum length found.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int l = 0, r = 1, maxLen = 1;

        string prevSign = "";

        while (r < arr.size())
        {
            int currLen = r - l + 1;
            if (arr[r - 1] > arr[r] && prevSign != ">")
            {
                maxLen = max(maxLen, currLen);
                r++;
                prevSign = ">";
            }
            else if (arr[r - 1] < arr[r] && prevSign != "<")
            {
                maxLen = max(maxLen, currLen);
                r++;
                prevSign = "<";
            }
            else
            {
                r = arr[r - 1] == arr[r]
                        ? r + 1 // Jump - get out of subarray because equal sign
                        : r;
                l = r - 1;   // Move left pointer to be behind r pointer and start
                             // new subarray
                prevSign = "";
            }
        }
        return maxLen;
    }
};
```
