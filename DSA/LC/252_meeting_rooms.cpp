#include <vector>
#include <algorithm>

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
    bool canAttendMeetings(std::vector<Interval> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs)
                  { return lhs.start < rhs.start; });

        for (int i{1}; i < intervals.size(); ++i)
        {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;
    }
};
