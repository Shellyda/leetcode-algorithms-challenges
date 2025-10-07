#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int> &nums)
    {
        n = nums.size();
        tree.resize(2 * n);

        for (int i = 0; i < n; ++i)
            tree[n + i] = nums[i];

        for (int i = n - 1; i > 0; --i)
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    void update(int pos, int value)
    {
        pos += n;
        tree[pos] = value;
        for (pos /= 2; pos > 0; pos /= 2)
            tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
    }

    int rangeMin(int l, int r)
    {
        vector<int> curWin = {tree.begin() + l, tree.begin() + r};
        priority_queue<int, vector<int>, greater<int>> minHeap(curWin.begin(), curWin.end());
        return minHeap.top();
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    SegmentTree segTree(nums);

    while (q--)
    {
        int type, start, end;
        cin >> type >> start >> end;
        if (type == 2)
        {
            cout << segTree.rangeMin(start, end) << endl;
        }
        else
        {
            segTree.update(start - 1, end);
        }
    }
    return 0;
}