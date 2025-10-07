#include <bits/stdc++.h>
using namespace std;

int getMin(vector<int> &window) // O(n)
{
    priority_queue<int, vector<int>, greater<int>> minHeap(window.begin(), window.end());
    return minHeap.top();
}

int main()
{
    int n, q;
    vector<int> nums;

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    while (q--)
    {
        int type, start, end;
        cin >> type >> start >> end;

        if (type == 2)
        {
            vector<int> curWin = {nums.begin() + start, nums.begin() + end};
            cout << getMin(curWin) << endl;
        }
        else
        {
            nums[start - 1] = end; // O(1)
        }
    }

    return 0;
}