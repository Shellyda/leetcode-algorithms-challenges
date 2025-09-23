#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inputStr, result;
    cin >> inputStr;

    for (char c : inputStr)
    {
        result.push_back(c);
        int n = result.size();
        if (n >= 3 && result[n - 3] == 'A' && result[n - 2] == 'B' && result[n - 1] == 'C')
        {
            result.pop_back();
            result.pop_back();
            result.pop_back();
        }

        cout << result << "\n";
        return 0;
    }
}