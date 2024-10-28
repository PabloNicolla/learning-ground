#include <math.h>

class Solution1
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }

        double res = helper(x, std::abs(static_cast<long>(n)));
        return (n >= 0) ? res : 1 / res;
    }

private:
    double helper(double x, long n)
    {
        if (n == 0)
        {
            return 1;
        }
        double half = helper(x, n / 2);
        return (n % 2 == 0) ? half * half : x * half * half;
    }
};

class Solution2
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;

        double ans = x;
        int abs_n = std::abs(n);

        for (int i{1}; i < abs_n; i++)
        {
            ans *= x;
        }

        return n < 0 ? 1 / ans : ans;
    }
};
