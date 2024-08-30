#include <limits>
long flippingBits(long n)
{
    return n ^ std::numeric_limits<unsigned int>::max();
}