#include <vector>
#include <queue>
using namespace std;

int getMinUnshippedParcels(vector<int> weights, int max_wt)
{
    priority_queue<int> maxHeap(weights.begin(), weights.end());

    int capacity = max_wt, sent = 0;

    while (!maxHeap.empty() && capacity > 0)
    {
        if (maxHeap.top() < capacity)
        {
            sent++;
            capacity--;
        }
        maxHeap.pop();
    }

    return weights.size() - sent;
};