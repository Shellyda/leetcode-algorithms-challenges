#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    priority_queue<int> small;                            // maxHeap
    priority_queue<int, vector<int>, greater<int>> large; // minHeap
    unordered_map<int, int> delayed;                      // lazy removal
    int smallSize = 0, largeSize = 0;

    vector<int> res;

    vector<int> medianSlidingWindow(vector<int> &nums, int k)
    {
        int l = 0, r = 0;

        while (r < nums.size())
        {
            addNum(nums[r]);

            if (r - l + 1 == k) // checking window size
            {
                res.push_back(getMedian(k));
                removeNum(nums[l]); // remove the num in the very left
                l++;
            }

            r++;
        }

        return res;
    }

private:
    void addNum(int num)
    {
        if (small.empty() || num <= small.top())
        {
            small.push(num);
            smallSize++;
        }
        else
        {
            large.push(num);
            largeSize++;
        }
        rebalance();
    }

    void removeNum(int num)
    {
        delayed[num]++; // mark future removal

        if (!small.empty() && num <= small.top())
        {
            smallSize--;
            if (num == small.top())
                cleanHeap(small);
        }
        else
        {
            largeSize--;
            if (!large.empty() && num == large.top())
                cleanHeap(large);
        }
        rebalance();
    }

    void rebalance()
    {
        if (smallSize > largeSize + 1)
        {
            large.push(small.top());
            small.pop();
            smallSize--;
            largeSize++;
            cleanHeap(small);
        }
        else if (largeSize > smallSize)
        {
            small.push(large.top());
            large.pop();
            largeSize--;
            smallSize++;
            cleanHeap(large);
        }
    }

    template <typename T>
    void cleanHeap(priority_queue<int, vector<int>, T> &heap)
    {
        while (!heap.empty() && delayed.count(heap.top()))
        {
            int x = heap.top();
            if (--delayed[x] == 0)
                delayed.erase(x);
            heap.pop();
        }
    }

    int getMedian(int k)
    {
        if (k % 2 == 1)
            return small.top();
        return small.top();
    }
};

int main()
{
    Solution s;
    vector<int> nums, result;
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    result = s.medianSlidingWindow(nums, k);

    for (int i = 0; i < result.size(); i++)
    {
        {
            if (i != result.size() - 1)
                cout << result[i] << " ";
            else
                cout << result[i];
        }
    }

    return 0;
}