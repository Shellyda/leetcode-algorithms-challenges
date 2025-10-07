#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<long long> maxHeap(gifts.begin(), gifts.end());
        while (k--)
        {
            int root = sqrt(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(root);
        }

        long long sum;

        while (!maxHeap.empty())
        {
            long long top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }

        return sum;
    }
};