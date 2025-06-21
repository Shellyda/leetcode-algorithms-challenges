#include <vector>
#include <queue>
using namespace std;

// O(Klogn)

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>>
            minHeap;

        for (auto p : points)
        {
            int distance = p[0] * p[0] + p[1] * p[1];

            pair<int, vector<int>> result = {distance, p};

            minHeap.push(result);
        }

        vector<vector<int>> res;

        for (int i = 0; i < k && !minHeap.empty(); ++i)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
