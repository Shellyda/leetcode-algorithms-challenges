#include <bits/stdc++.h>
using namespace std;

long long diff = LLONG_MAX, totalSum = 0;

void backtracking(int i, vector<long long> &nums, long long group1Sum)
{
    if (i >= nums.size())
    {
        long long group2Sum = totalSum - group1Sum;
        diff = min(diff, abs(group1Sum - group2Sum));
        return;
    }

    backtracking(i + 1, nums, group1Sum + nums[i]); // include

    backtracking(i + 1, nums, group1Sum); // not include
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> weights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
        totalSum += weights[i];
    }

    backtracking(0, weights, 0);

    cout << diff << endl;
    return 0;
}
