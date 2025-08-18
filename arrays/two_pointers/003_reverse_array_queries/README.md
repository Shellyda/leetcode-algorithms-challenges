# Reverse Array Queries

- 🧩 Problem link: [Amazon HackerRank Demo OA practice test](https://www.hackerrank.com/test/5fl6sika8gh)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- The function applies a sequence of **reverse operations** on an array.
- For each operation `[left, right]`:

  - Reverse the subarray between indices `left` and `right` (inclusive).
  - This is done with a **two-pointer swap** until `left >= right`.

- After applying all operations, return the final modified array.

## 🕒 Time and Space Complexity

- Time: O(m \* n)
- Space: O(1)

> Where `n` is `operations.size()` and `m` is `arr.size()`

## ✅ Solution

```cpp
vector<int> performOperations(vector<int> arr, vector<vector<int>> operations)
{
    for (vector<int> curOp : operations) // O(n)
    {
        int left = curOp[0], right = curOp[1];

        while (left < right) // O(m)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    return arr;
};
```
