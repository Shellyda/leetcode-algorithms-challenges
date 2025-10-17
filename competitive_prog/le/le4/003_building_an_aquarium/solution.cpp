#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long x;
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long low = 1;
        long long high = *max_element(a.begin(), a.end()) + x;

        while (low < high)
        {
            long long mid = (low + high + 1) / 2;

            long long water = 0;
            for (long long h : a)
            {
                if (mid > h)
                    water += mid - h;
                if (water > x)
                    break;
            }

            if (water <= x)
                low = mid;
            else
                high = mid - 1;
        }

        cout << low << endl;
    }
}
