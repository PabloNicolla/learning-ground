#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int cur{nums[0]};
        int max{nums[0]};
        for (int i{1}; i < nums.size(); ++i)
        {
            cur = std::max(cur + nums[i], nums[i]);
            max = std::max(cur, max);
        }
        return max;
    }
};