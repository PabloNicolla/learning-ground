#include <vector>
#include <algorithm>

class Solution
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
    {
        int ans{};
        std::sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs)
                  { return lhs[0] < rhs[0]; });
        int end = intervals.size() > 0 ? intervals[0][1] : 0;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (end > intervals[i][0])
            {
                ++ans;
                if (end > intervals[i][1])
                {
                    end = intervals[i][1];
                }
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};
