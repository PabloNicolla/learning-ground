#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution1
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;
        sum >>= 1;
        unordered_set<int> dp = {0};
        for (int num : nums)
        {
            vector<int> temp;
            for (int val : dp)
            {
                int total = num + val;
                if (total == sum)
                    return true;
                if (total < sum)
                {
                    temp.push_back(total);
                }
            }
            dp.insert(temp.begin(), temp.end());
        }
        return false;
    }
};

class Solution2
{
public:
    bool canPartition(const std::vector<int> &nums)
    {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
        {
            return false;
        }

        std::unordered_set<int> dp{};
        const int half = sum / 2;
        dp.insert(0);

        for (int num : nums)
        {
            std::unordered_set<int> next_dp{};
            for (int value : dp)
            {
                if (value + num == half)
                {
                    return true;
                }
                next_dp.insert(value + num);
                next_dp.insert(value);
            }
            dp = std::move(next_dp);
        }

        return false;
    }
};