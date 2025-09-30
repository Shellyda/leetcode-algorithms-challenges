#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int> tickets; // order and allow duplicates
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        tickets.insert(price); // logn
    }

    for (int i = 0; i < m; i++)
    {
        int currPrice;
        cin >> currPrice;
        auto it = tickets.upper_bound(currPrice); // logn -> val > currPrice

        // if points to beginning means all prices are bigger than curr
        if (it == tickets.begin())
        {
            cout << -1 << endl;
        }
        else // if not -> I want the prev val found in upper bound
        {
            it--;
            cout << *it << endl;
            tickets.erase(it); // O(1)
        }
    }

    return 0;
}