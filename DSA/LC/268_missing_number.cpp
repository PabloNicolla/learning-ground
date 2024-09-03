#include <vector>

class Solution1
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        int ans{};

        for (int i{}; i <= nums.size(); i++)
        {
            ans ^= i;
        }

        for (int num : nums)
        {
            ans ^= num;
        }

        return ans;
    }
};

class Solution2
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        long long int sum = 0;
        for (auto &i : nums)
            sum += i;
        int n = nums.size();
        return (n * (n + 1)) / 2 - sum;
    }
};
