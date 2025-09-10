#include <queue>
#include <vector>
#include <functional>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> small;                            // maxHeap
    priority_queue<int, vector<int>, greater<int>> large; // minHeap

    MedianFinder() {}

    void addNum(int num)
    {
        small.push(num);
        if (!large.empty() && small.top() > large.top())
        {
            large.push(small.top());
            small.pop();
        }

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

    double findMedian()
    {
        // odd len case
        if (small.size() > large.size())
        {
            return (double)small.top();
        }
        else if (large.size() > small.size())
        {
            return (double)large.top();
        }

        // even len case
        return (double)(small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */