#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        int k;
        cin >> k;

        unordered_map<string, int> categories; // category -> qtd of attr in this category

        for (int i = 0; i < k; i++)
        {
            string item, category;
            cin >> item >> category;
            categories[category]++;
        }

        long long total = 1;
        for (auto &[name, qtd] : categories)
            total *= (qtd + 1);

        cout << total - 1 << "\n";
    }

    return 0;
}
