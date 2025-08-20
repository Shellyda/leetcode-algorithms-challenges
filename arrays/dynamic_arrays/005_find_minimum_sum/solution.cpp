#include <vector>
using std::vector;

long findMinimumSum(vector<int> power)
{
    long long res = 0;

    for (int i = 0; i + 1 < power.size(); ++i)
    { // O(n)
        if (power[i] > power[i + 1])
        {
            res += (long long)(power[i] - power[i + 1]);
        }
    }

    return res;
}