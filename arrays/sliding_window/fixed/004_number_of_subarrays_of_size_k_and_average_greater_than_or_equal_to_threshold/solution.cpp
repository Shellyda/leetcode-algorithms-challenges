#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Solution
{

private:
    bool avgInRange(queue<int> currWindow, int threshold)
    {
        int sum = 0, k = currWindow.size();
        while (!currWindow.empty())
        {
            sum += currWindow.front();
            currWindow.pop();
        }

        int avg = sum / k;

        return avg >= threshold;
    }

public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        queue<int> window; // queue -> FIFO
        int r = 0, res = 0;

        for (int r : arr)
        {
            window.push(r);

            if (window.size() == k)
            {
                if (avgInRange(window, threshold))
                    res++;
                window.pop();
            }
        }

        return res;
    }
};
