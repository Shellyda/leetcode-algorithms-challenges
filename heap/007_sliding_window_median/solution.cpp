#include <queue>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    priority_queue<double> small;                                  // maxHeap
    priority_queue<double, vector<double>, greater<double>> large; // minHeap

    vector<double> res;

    // O(n*klogk)

    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int l = 0, r = 0, balance = k;

        while (r < nums.size())
        {
            if (balance > 0)
            {
                balance--;
                insert(nums[r]);
                r++;
            }
            else
            {
                double median = getMedian();
                res.push_back(median);

                // Clear

                balance = k;
                l++;
                r = l;

                small = priority_queue<double>();
                large = priority_queue<double, vector<double>, greater<double>>();
            }
        }

        if (balance == 0)
            res.push_back(getMedian()); // get the last case

        return res;
    }

private:
    void insert(int num)
    {
        if (!large.empty() && num > large.top())
            large.push(num);
        else
            small.push(num);

        if (small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }
        else if (large.size() > small.size() + 1)
        {
            small.push(large.top());
            large.pop();
        }
    }

    double getMedian()
    {
        if (small.size() > large.size())
        {
            return (double)small.top();
        }
        else if (large.size() > small.size())
        {
            return (double)large.top();
        }

        return (double)(large.top() + small.top()) / 2.0;
    }
};