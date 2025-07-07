# Merge Sort

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/mergeSort)
- 🚦 Difficulty: 🟡 Medium

## Purpose

Implement Merge Sort.

Merge Sort is a divide-and-conquer algorithm for sorting an array or list of elements. It works by recursively dividing the unsorted list into `n` sub-lists, each containing one element. Then, it repeatedly merges sub-lists to produce new sorted sub-lists until there is only one sub-list remaining.

### Objective:

Given a list of key-value pairs, sort the list by `key` using Merge Sort. If two key-value pairs have the same `key`, maintain their relative order in the sorted list.

### Input:

- `pairs` - a list of key-value pairs, where each key-value has an integer `key` and a string value. `(0 <= pairs.length <= 100)`.

### Example 1:

```cpp
Input:
pairs = [(5, "apple"), (2, "banana"), (9, "cherry"), (1, "date"), (9, "elderberry")]

Output:
[(1, "date"), (2, "banana"), (5, "apple"), (9, "cherry"), (9, "elderberry")]
```

Note: As you can see, the solution is always stable. The two pairs with the key 9 maintained their relative positions.

### Example 2:

```cpp
Input:
pairs = [(3, "cat"), (2, "dog"), (3, "bird")]

Output:
[(2, "dog"), (3, "cat"), (3, "bird")]
```

## 🕒 Time and Space Complexity

- Time: O(nlogn)
- Space: O(n + logn) => O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    vector<Pair> mergeSort(vector<Pair> &pairs)
    {
        if (pairs.size() <= 1)
            return pairs;

        int m = (pairs.size() - 1) / 2;

        vector<Pair> left = {pairs.begin() + 0, pairs.begin() + m + 1};
        vector<Pair> right = {pairs.begin() + m + 1, pairs.begin() + pairs.size()};

        mergeSort(left);
        mergeSort(right);

        merge(pairs, left, right);

        return pairs;
    }

    void merge(vector<Pair> &pairs, vector<Pair> left, vector<Pair> right)
    {
        int i = 0, k = 0, j = 0;

        while (i < left.size() && j < right.size())
        {
            if (left[i].key <= right[j].key)
            {
                pairs[k] = left[i++];
            }
            else
            {
                pairs[k] = right[j++];
            }
            k++;
        }

        while (i < left.size())
        {
            pairs[k++] = left[i++];
        }

        while (j < right.size())
        {
            pairs[k++] = right[j++];
        }
    }
};
```
