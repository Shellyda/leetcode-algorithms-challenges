# Quick Sort

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/quickSort)
- 🚦 Difficulty: 🟡 Medium

## Purpose

Implement Quick Sort.

Quick Sort is a divide-and-conquer sorting algorithm that works by partitioning an array into two smaller sub-arrays based on a pivot element. The elements less than the pivot go to the left sub-array and those greater go to the right sub-array. The algorithm then recursively sorts the sub-arrays.

### Objective:

Given a list of key-value pairs, sort the list by key using Quick Sort. For each partitioning step:

1. Use the right-most element as the pivot.
2. Elements less than the pivot should be placed to the left of the pivot, and elements greater than or equal to the pivot should be placed to the right of the pivot.

The correctness of your solution will be determined based on these requirements.

### Input:

- `pairs` - a list of key-value pairs, where each key-value has an integer `key` and a string value. `(0 <= pairs.length <= 100)`.

### Example 1:

```cpp
Input:
pairs = [(3, "cat"), (2, "dog"), (3, "bird")]

Output:
[(2, "dog"), (3, "bird"), (3, "cat")]
```

Note: As you can see, the solution is not necessarily stable. The two pairs with the key 3 have switched their relative positions.

### Example 2:

```cpp
Input:
pairs = [(5, "apple"), (9, "banana"), (9, "cherry"), (1, "date"), (9, "elderberry")]

Output:
[(1, "date"), (5, "apple"), (9, "elderberry"), (9, "cherry"), (9, "banana")]
```

## 🕒 Time and Space Complexity

- Time: O(nlogn) - General result, O(n^2) - Worst case\*
- Space: O(n)

\*This is because our partitioning will not be effective and we will end up with a partition of size `n-1` and `0` respectively, making the height of our recursion tree n

## ✅ Solution

```cpp
class Solution
{
public:
    // Implementation of QuickSort
    vector<Pair> quickSort(vector<Pair> &pairs)
    {
        quickSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

private:
    void quickSortHelper(vector<Pair> &arr, int s, int e)
    {
        if (e - s + 1 <= 1)
        {
            return;
        }

        Pair pivot = arr[e]; // pivot is the last element
        int changePoint = s; // pointer for the left side

        // Partition: elements smaller than pivot on the left side
        for (int i = s; i < e; ++i)
        {
            if (arr[i].key < pivot.key)
            {
                swap(arr[changePoint], arr[i]);
                changePoint++;
            }
        }

        // Move pivot in-between left & right sides
        arr[e] = arr[changePoint];
        arr[changePoint] = pivot;

        // Quick sort left side
        quickSortHelper(arr, s, changePoint - 1);

        // Quick sort right side
        quickSortHelper(arr, changePoint + 1, e);
    }
};
```
