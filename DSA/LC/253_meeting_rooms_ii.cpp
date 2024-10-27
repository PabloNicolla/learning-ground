#include <algorithm>
#include <vector>

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    int minMeetingRooms(std::vector<Interval> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs)
                  { return lhs.start < rhs.start; });

        std::vector<Interval> next_day{};
        int days{0};

        while (!intervals.empty())
        {
            int end = intervals.size() > 0 ? intervals[0].end : 0;
            for (size_t i{1}; i < intervals.size(); ++i)
            {
                if (intervals[i].start < end)
                {
                    if (intervals[i].end > end)
                    {
                        next_day.push_back(intervals[i]);
                    }
                    else
                    {
                        next_day.push_back(intervals[i - 1]);
                        end = intervals[i].end;
                    }
                }
                else
                {
                    end = intervals[i].end;
                }
            }
            intervals = std::move(next_day);
            ++days;
        }

        return days;
    }
};
