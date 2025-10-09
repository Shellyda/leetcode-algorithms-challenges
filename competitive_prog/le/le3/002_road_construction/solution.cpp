#include <bits/stdc++.h>
using namespace std;

int findParent(int x, vector<int> &parent)
{
    if (parent[x] != x)
        parent[x] = findParent(parent[x], parent);
    return parent[x];
}

bool unionSets(int a, int b, vector<int> &parent, vector<int> &size, int &maxSize)
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a == b)
        return false;

    if (size[a] < size[b])
        swap(a, b);

    parent[b] = a;
    size[a] += size[b];

    if (size[a] > maxSize)
        maxSize = size[a];
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1), size(n + 1, 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int componentCount = n;
    int maxSize = 1;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (unionSets(x, y, parent, size, maxSize))
            componentCount--;
        cout << componentCount << " " << maxSize << endl;
    }

    return 0;
}
