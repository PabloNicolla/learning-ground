#include <vector>
class Solution
{
public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        const int size = cost.size();
        if (size <= 1)
        {
            return 0;
        }
        std::vector<int> memo(size, 0);
        memo[size - 1] = cost[size - 1];
        memo[size - 2] = cost[size - 2];

        for (int i = size - 3; i >= 0; --i)
        {
            int price = cost[i];
            memo[i] = std::min(price + memo[i + 1], price + memo[i + 2]);
        }

        return std::min(memo[0], memo[1]);
    }
};
