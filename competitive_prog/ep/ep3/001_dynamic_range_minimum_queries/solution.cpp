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
        int res = INT_MAX;
        l += n;
        r += n;
        while (l < r)
        {
            if (l % 2)
                res = min(res, tree[l++]);
            if (r % 2)
                res = min(res, tree[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
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
            if (start == end)
            {
                cout << segTree.rangeMin(start - 1, start) << endl;
            }
            else
            {
                cout << segTree.rangeMin(start - 1, end) << endl;
            }
        }
        else
        {
            segTree.update(start - 1, end);
        }
    }
    return 0;
}