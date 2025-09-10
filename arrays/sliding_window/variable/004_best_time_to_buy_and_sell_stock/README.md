# Best Time to Buy and Sell Stock

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- 🚦 Difficulty: 🟢 Easy

## 💡 Approach

* Use two pointers:

  * `l` = **buy day** (initially 0)
  * `r` = **sell day** (starts at 1 and moves forward)

* Loop through the prices starting from day 1 (`r = 1`):

  * If `prices[r] > prices[l]`:

    * There's profit to be made → calculate `profit = prices[r] - prices[l]`
    * Update `res` with the maximum profit so far.
  * Else:

    * `prices[r]` is lower or equal → set `l = r` (we found a cheaper day to buy)

* Return the maximum profit found (`res`).


## 🕒 Time and Space Complexity
- Time: O(n)
- Space: O(1)

## ✅ Solution

```cpp
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
```
