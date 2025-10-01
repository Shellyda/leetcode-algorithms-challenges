#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    multiset<int> list; // order and allow duplicates
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        list.insert(num); // logn
        nums.push_back(num);
    }

    unordered_set<int> window;
    int l = 0;

    for (int r = 0; r < nums.size(); r++)
    {
        if (r - l == k)
        {
            window.erase(nums[l]);
            l++;
        }
        window.insert(nums[r]);
    }

    return 0;
}