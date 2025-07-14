#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap;
        for (int val : stones)
        { // O(n.logn)

            maxHeap.push(val); // logn
        }

        int res = maxHeap.size() == 1 ? maxHeap.top() : 0;

        while (!maxHeap.empty() && maxHeap.size() != 1) // logn
        {
            int x = maxHeap.top(); // O(1)
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if (x != y)
            {
                y = x < y ? y - x : x - y;

                maxHeap.push(y);
            }

            if (maxHeap.size() == 1)
            {
                res = maxHeap.top();
            }
        }

        return res;
    }
};

int main()
{
    Solution s;

    vector<int> stones = {1};

    s.lastStoneWeight(stones);
    return 0;
}
