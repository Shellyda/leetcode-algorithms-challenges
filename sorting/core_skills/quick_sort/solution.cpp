#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pair
{
public:
    int key;
    string value;

    Pair(int key, string value) : key(key), value(value) {}
};

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

int main()
{
    vector<Pair> pairs = {
        Pair(5, "apple"),
        Pair(9, "banana"),
        Pair(9, "cherry"),
        Pair(1, "date"),
        Pair(9, "elderberry")};

    Solution solution;
    vector<Pair> sortedPairs = solution.quickSort(pairs);

    cout << "Sorted pairs by key:\n";
    for (const auto &p : sortedPairs)
    {
        cout << "(" << p.key << ", " << p.value << ")\n";
    }

    return 0;
}
