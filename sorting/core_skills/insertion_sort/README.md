# Insertion Sort

- 🧩 Problem link: [Neetcode](https://neetcode.io/problems/insertionSort)
- 🚦 Difficulty: 🟢 Easy

## Purpose

Implement Insertion Sort and return intermediate states.

Insertion Sort is a simple sorting algorithm that builds the sorted list one element at a time, from left to right. It works by repeatedly taking an element from the unsorted portion and inserting it into its correct position in the sorted portion of the list.

### Objective:

Given a list of key-value pairs, sort the list by `key` using Insertion Sort. Return a list of lists showing the state of the array after each insertion. If two key-value pairs have the same `key`, maintain their relative order in the sorted list.

### Input:

- `pairs` - a list of key-value pairs, where each key-value has an integer `key` and a string value. `(0 <= pairs.length <= 100)`.

### Example 1:

```cpp
Input:
pairs = [(5, "apple"), (2, "banana"), (9, "cherry")]

Output:
[[(5, "apple"), (2, "banana"), (9, "cherry")],
 [(2, "banana"), (5, "apple"), (9, "cherry")],
 [(2, "banana"), (5, "apple"), (9, "cherry")]]
```

Notice that the output shows the state of the array after each insertion. The last state is the final sorted array. There should be pairs.length states in total.

### Example 2:

```cpp
Input:
pairs = [(3, "cat"), (3, "bird"), (2, "dog")]

Output:
[[(3, "cat"), (3, "bird"), (2, "dog")],
 [(3, "cat"), (3, "bird"), (2, "dog")],
 [(2, "dog"), (3, "cat"), (3, "bird")]]
```

In this example, you can observe that the pairs with key=3 ("cat" and "bird") maintain their relative order, illustrating the stability of the Insertion Sort algorithm.

## 🕒 Time and Space Complexity

- Time: O(n)\* - Best, O(n^2) - Worst
- Space: O(1)

\*If fully, or nearly sorted, O(n)

## ✅ Solution

```cpp
class Solution
{
public:
    vector<vector<Pair>> insertionSort(vector<Pair> &pairs)
    {
        vector<vector<Pair>> set;
        if (pairs.empty())
            return set;

        for (int i = 1; i < pairs.size(); i++)
        {
            set.push_back(pairs); // result from each insertion

            int j = i - 1;
            while (j >= 0 && pairs[j].key > pairs[j + 1].key)
            {
                auto temp = pairs[j + 1];
                pairs[j + 1] = pairs[j];
                pairs[j] = temp;
                j--;
            }
        }

        set.push_back(pairs); // last result

        return set;
    }
};
```
