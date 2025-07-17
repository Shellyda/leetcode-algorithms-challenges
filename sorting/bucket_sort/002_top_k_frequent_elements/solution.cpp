#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums)
        {
            count[n]++;
        }

        for (const auto &pair : count)
        {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> results;
        for (int i = freq.size() - 1; i > 0; --i)
        {
            for (int n : freq[i])
            {
                results.push_back(n);
                if (results.size() == k)
                    return results;
            }
        }

        return results;
    }
};