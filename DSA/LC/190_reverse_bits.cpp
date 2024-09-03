#include <cstdint>

class Solution1
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int index = 32;
        uint32_t ans{};

        if (n == 0)
            return ans;

        while (n > 0)
        {
            ans <<= 1;
            if (n & 1)
            {
                ans |= 1;
            }
            n /= 2;
            --index;
        }
        ans <<= index;
        return ans;
    }
};

class Solution2
{
public:
    uint32_t reverseBits(uint32_t n)
    {

        uint32_t res = 0;

        for (uint32_t i = 0; i < 32; i++)
        {
            res = (1 & (n >> i)) << 31 - i | res;
        }

        return res;
    }
};