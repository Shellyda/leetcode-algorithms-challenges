# Koko Eating Bananas

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/koko-eating-bananas/description/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

Define the search boundaries:

1. Minimum (l) = 1 (she must eat at least 1 banana per hour).
2. Maximum (r) = the largest pile of bananas (if she eats an entire pile per hour).
3. Search for the smallest possible k using binary search:
   - For each `k`, calculate the total time needed (totalTime) by summing up `ceil(p / k)` for each pile p.
   - If `totalTime <= h`, it means `k` is a valid answer, but we try to find a smaller one by setting `r = k - 1`.
   - If `totalTime > h`, then `k` is too slow, so we increase it by setting `l = k + 1`.

## 🕒 Time and Space Complexity

- Time: O(n\*logm)
- Space: O(1)

> Where `n` is the length of the input array piles and `m` is the maximum number of bananas in a pile.

## ✅ Solution

```cpp
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r)
        {
            int k = (l + r) / 2;

            long long totalTime = 0;
            for (int p : piles)
            {
                totalTime += ceil(static_cast<double>(p) / k);
            }
            if (totalTime <= h)
            {
                res = k;
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }
        return res;
    }
};
```
