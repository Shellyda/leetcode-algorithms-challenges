# Find minimum sum

- The "Amazon OA – Min sum possible" type of question
- Find the mim sum to make array non-decreasing

  > A set of `n` servers are used for horizontally scaling an application. The goal is to have the computational power of the servers in non-decreasing order. To do so, you can increase the computational power of each server in any contiguous segment by `x`. Choose the values of `x` such that after the computational powers are in non-decreasing order, the sum of the `x` values is minimum.

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/steps-to-make-array-non-decreasing/) (Similar question)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

The function `findMinimumSum` takes a vector of integers `power` and computes the **total amount that the array decreases** when moving from left to right.

- If `power[i] > power[i+1]`, it means there’s a **drop** at that position.
- The function adds the difference `(power[i] - power[i+1])` to the result.
- Otherwise, if `power[i] <= power[i+1]`, nothing is added.

So essentially, it **accumulates the sum of all decreases between consecutive elements** in the array.

```cpp
power = [5, 3, 6, 2]
```

- `5 -> 3` → drop of `2` → add `2`.
- `3 -> 6` → increase → add `0`.
- `6 -> 2` → drop of `4` → add `4`.

Final result = `2 + 0 + 4 = 6`.

## 🕒 Time and Space Complexity

- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
long findMinimumSum(vector<int> power)
{
    long long res = 0;

    for (int i = 0; i + 1 < power.size(); ++i)
    { // O(n)
        if (power[i] > power[i + 1])
        {
            res += (long long)(power[i] - power[i + 1]);
        }
    }

    return res;
}
```
