#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> scores(N, 0);

    for (int i = 0; i < Q; i++)
    {
        int A;
        cin >> A;
        scores[A - 1]++;
    }

    for (int i = 0; i < N; i++)
    {
        if ((K - (Q - scores[i])) > 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
