#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;

        for (int n : nums)
        {
            pq.push(n);
        }

        int res;

        for (int i = 0; i < k; ++i)
        {
            int top = pq.top();
            if (i == k - 1)
            {
                res = top;
            }

            pq.pop();
        }

        return res;
    }
};
