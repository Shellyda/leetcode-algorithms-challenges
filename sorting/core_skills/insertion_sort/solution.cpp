
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
