#include <iostream>
#include <vector>
using namespace std;

// Definition for a Pair
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
