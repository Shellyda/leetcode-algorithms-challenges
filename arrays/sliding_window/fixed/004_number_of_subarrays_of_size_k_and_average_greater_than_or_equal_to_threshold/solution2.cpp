#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        queue<int> window;
        int sum = 0, res = 0;

        for (int num : arr)
        {
            window.push(num);
            sum += num;

            if (window.size() == k)
            {
                int avg = sum / k;
                if (avg >= threshold)
                    res++;

                sum -= window.front();
                window.pop();
            }
        }

        return res;
    }
};
