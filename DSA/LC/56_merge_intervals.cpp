#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::vector<std::vector<int>> ans{};

        std::sort(intervals.begin(), intervals.end(), [](const auto &v1, const auto &v2) -> bool
                  { return v1[0] < v2[0]; });

        for (size_t i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i - 1][1] < intervals[i][0])
            {
                ans.push_back(intervals[i - 1]);
            }
            else
            {
                intervals[i][0] = std::min(intervals[i - 1][0], intervals[i][0]);
                intervals[i][1] = std::max(intervals[i - 1][1], intervals[i][1]);
            }
        }

        ans.push_back(intervals.back());

        return ans;
    }
};