#include <vector>
#include <limits>
#include <iostream>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int curr_price{}; curr_price <= amount; ++curr_price)
        {
            for (const auto coin : coins)
            {
                if (curr_price - coin >= 0 && dp[curr_price - coin] + 1 < dp[curr_price])
                {
                    dp[curr_price] = dp[curr_price - coin] + 1;
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main()
{
    Solution s{};
    std::vector<int> coins{1, 5, 10};
    auto a = s.coinChange(coins, 12);

    std::cout << a << "\n\n";
    return 0;
}