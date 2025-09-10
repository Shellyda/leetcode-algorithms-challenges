#include <vector>
#include <algorithm>
using std::max;
using std::vector;

/*
int res = 0, l = 0;
for r in range(len(prices)):
    if(r - l > res) {
        res = r - l;
    } else {
        l = r;
    }
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0, res = 0;

        for (int r = 1; r < prices.size(); r++)
        {
            if (prices[l] < prices[r])
            {
                int profit = prices[r] - prices[l];
                res = max(res, profit);
            }
            else
            {
                l = r;
            }
        }
        return res;
    }
};