#include <cstdint>
using std::uint32_t;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return countBits(n);
    }

private:
    int countBits(uint32_t n)
    {
        int count = 0;

        while (n > 0)
        {
            if ((n & 1))
                count++;
            n = n >> 1; // shift right - diving the given integer by 2 - halving
        }

        return count;
    }
};
