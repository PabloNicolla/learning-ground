#include <limits>

class Solution1
{
public:
    int reverse(int x)
    {
        const int MIN = -2147483648; // -2^31
        const int MAX = 2147483647;  // 2^31 - 1

        int res = 0;
        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;

            if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
                return 0;
            if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
                return 0;
            res = (res * 10) + digit;
        }

        return res;
    }
};

class Solution2
{
public:
    int reverse(int x)
    {
        long long ans{};
        while (x != 0)
        {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        if (ans > 0 && ans > std::numeric_limits<int>().max())
        {
            return 0;
        }
        else if (ans < 0 && ans < std::numeric_limits<int>().min())
        {
            return 0;
        }
        return static_cast<int>(ans);
    }
};
