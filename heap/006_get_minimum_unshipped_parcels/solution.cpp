#include <vector>
#include <algorithm>
#include <functional>
using std::greater;
using std::sort;
using std::vector;

int getMinUnshippedParcels(vector<int> weights, int max_wt)
{
    sort(weights.begin(), weights.end(), greater<int>()); // O(n log n)

    int capacity = max_wt, sent = 0;

    for (int w : weights)
    { // O(n)
        if (w < capacity)
        {
            sent++;
            capacity--;

            if (capacity == 0)
                break;
        }
    }

    return weights.size() - sent;
}