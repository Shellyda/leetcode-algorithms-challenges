#include <cstdint>
using std::uint32_t;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++)
        {
            result <<= 1;    // shift result to the left
            result |= n & 1; // add the last bit of n to result
            n >>= 1;         // shift n to the right
        }

        return result;
    }
};
