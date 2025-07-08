# First Bad Version

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/first-bad-version/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- In this case the latest version of the product fails and we want to find the first bad version
- So, I thought in the array like this [`l pointer ->`good,good,good,bad `<- first bad version`,bad,bad,bad,bad `<- r pointer`]
- Used `binSearch` to find this point, going like this:
  1. always set `r` pointer to `mid` version number when finding a bad version
  2. if is not a bad version, move `l` pointer to `mid + 1`
  3. Go back to step 1

## 🕒 Time and Space Complexity

- Time: O(logn)
- Space: O(1)

## ✅ Solution

```cpp
class Solution
{
public:
    int firstBadVersion(int n)
    {
        return binSearch(1, n);
    }

    int binSearch(int l, int r)
    {
        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (isBadVersion(m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }

        return r;
    }
};
```
