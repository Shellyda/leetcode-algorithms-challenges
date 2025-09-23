#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N;

    vector<int> prices(N);

    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int input;
        cin >> input;

        int result = upper_bound(prices.begin(), prices.end(), input) - prices.begin();

        cout << result << endl;
    }

    return 0;
}
