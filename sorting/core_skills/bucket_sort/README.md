# Bucket Sort

## Purpose

- Study Bucket Sort implementation

## 🕒 Time and Space Complexity

- Time: O(n)\*
- Space: O(1)

\*Assuming all values in the input are in a specified range.

## ✅ Solution

```cpp
vector<int> bucketSort(vector<int> &arr)
{
    // Assuming arr only contains 0, 1 or 2
    int counts[] = {0, 0, 0};

    // Count the quantity of each val in arr
    for (int n : arr)
    {
        counts[n]++;
    }

    int i = 0;
    for (int n = 0; n < 3; n++)
    {
        for (int j = 0; j < counts[n]; j++)
        {
            arr[i] = n;
            i++;
        }
    }
    return arr;
}
```
