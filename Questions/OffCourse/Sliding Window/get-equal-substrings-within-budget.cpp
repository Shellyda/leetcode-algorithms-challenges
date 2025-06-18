#include <string>
#include <algorithm>
using std::max;
using std::string;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int l = 0, res = 0, costCount = 0;

        for (int r = 0; r < s.size(); r++)
        {
            costCount += abs(s[r] - t[r]);

            while (costCount > maxCost)
            {
                costCount -= abs(s[l] - t[l]);
                l += 1;
            }

            int size = r - l + 1;

            res = max(res, size);
        }

        return res;
    }
};

int main()
{
    Solution s;

    int max = 3;

    s.equalSubstring("abcd", "bcdf", max);

    return 0;
}