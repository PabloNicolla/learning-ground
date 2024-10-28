#include <vector>

class Solution1
{
public:
    int jump(std::vector<int> &nums)
    {
        std::vector<int> dp(nums.size(), -1);
        dp.back() = 0;

        for (int cur_pos = nums.size() - 2; cur_pos >= 0; --cur_pos)
        {
            int jump_len = nums[cur_pos];

            if (cur_pos + jump_len >= nums.size())
            {
                dp[cur_pos] = 1;
                continue;
            }

            for (int j{1}; j <= jump_len; j++)
            {
                if (dp[cur_pos + j] != -1)
                {
                    if (dp[cur_pos] == -1)
                        dp[cur_pos] = dp[cur_pos + j] + 1;
                    else
                        dp[cur_pos] = std::min(dp[cur_pos], dp[cur_pos + j] + 1);
                }
            }
        }
        return dp[0];
    }
};
