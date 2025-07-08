# Binary Search

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/binary-search/description/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

- Apply the Binary Search concept

## 🕒 Time and Space Complexity

- Time: O(logn)
- Space: O(1)

## ✅ Solution

```cpp
int binarySearch(vector<int> arr, int target)
{
    int l = 0, r = arr.size() - 1;

    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (target > arr[mid])
        {
            l = mid + 1;
        }
        else if (target < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
```
