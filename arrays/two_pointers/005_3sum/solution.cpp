#include <vector>
#include <set>
#include <algorithm>
using std::set;
using std::sort;
using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> triplets;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;

            while (l < r)
            {
                int currSum = nums[i] + nums[l] + nums[r];

                if (currSum == 0)
                {
                    triplets.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if (currSum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        for (auto vec : triplets)
            res.push_back(vec);

        return res;
    }
};