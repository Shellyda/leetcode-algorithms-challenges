#include <unordered_map>
using std::unordered_map;

class Solution
{
public:
    int climbStairs(int n)
    {
        unordered_map<int, int> cache;
        return memoization(n, cache);
    }

private:
    int memoization(int n, unordered_map<int, int> &cache)
    {
        if (n <= 2)
            return n;

        if (cache.count(n))
            return cache[n];

        int result = memoization(n - 1, cache) + memoization(n - 2, cache);
        cache[n] = result;

        return cache.at(n);
    }
};
