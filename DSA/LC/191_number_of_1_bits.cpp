#include <cstdint>

class Solution1
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        while (n > 0)
        {
            count += n & 1;
            n = n >> 1;
        }

        return count;
    }
};

class Solution2
{
public:
    int hammingWeight(uint32_t n)
    {
        int bitCount{};
        while (n > 0)
        {
            if ((n ^ 1) < n)
            {
                ++bitCount;
            }
            n >>= 1;
        }
        return bitCount;
    }
};

class Solution3
{
public:
    int hammingWeight(uint32_t n)
    {
        int bitCount{};
        while (n > 0)
        {
            bitCount += n % 2;
            n >>= 1;
        }
        return bitCount;
    }
};
