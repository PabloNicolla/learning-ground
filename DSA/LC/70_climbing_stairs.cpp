#include <vector>
#include <functional>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution2
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;

        int total = 1;
        int prev = 1;
        for (int i = 1; i < n; i++)
        {
            int temp = total;
            total += prev;
            prev = temp;
        }
        return total;
    }
};

class Solution3
{
public:
    int climbStairs(int n)
    {
        std::function<int(int)> rec = [&](int index)
        {
            if (index + 1 == n)
                return 2;
            if (index == n)
                return 1;
            if (index > n)
                return 0;
            return rec(index + 1) + 2;
        };
        return rec(0);
    }
};
