#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;
        indices.reserve(nums.size() * 2);

        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int need = target - nums[i];
            auto it = indices.find(need);
            if (it != indices.end())
            {
                return {it->second + 1, i + 1};
            }
            indices[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    Solution s;
    vector<int> nums, result;
    int n, target;

    cin >> n >> target;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // sort(nums.begin(), nums.end());
    result = s.twoSum(nums, target);

    if (!result.empty())
    {
        for (int i = 0; i < result.size(); i++)
        {
            if (i != result.size() - 1)
                cout << result[i] << " ";
            else
                cout << result[i];
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}