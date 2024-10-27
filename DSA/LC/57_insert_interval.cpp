#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
    {
        int insert_pos = 0;

        for (const auto &interval : intervals)
        {
            // [... end_x < new_begin, new_begin <= end_y, ...]
            if (newInterval[0] /*new_begin*/ <= interval[1] /*end_y*/)
            {
                break;
            }
            insert_pos++;
        }

        // [... end_x < new_begin]
        if (insert_pos == intervals.size())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        // [... end_x < new_begin, new_end < begin_y, ...]
        if (newInterval[1] /*new_end*/ < intervals[insert_pos][0] /*begin_y*/)
        {
            intervals.insert(intervals.begin() + insert_pos, newInterval);
            return intervals;
        }

        // [... end_x < merged_begin, begin_y <= new_end, ...]
        if (intervals[insert_pos][0] /*begin_y*/ > newInterval[0])
        {
            intervals[insert_pos][0] = newInterval[0]; // merged_begin
        }

        // [... end_y >= new_end, ...]
        if (intervals[insert_pos][1] /*end_y*/ >= newInterval[1] /*new_end*/)
        {
            return intervals;
        }

        // [... end_y < new_end, ...]
        intervals[insert_pos][1] = newInterval[1];
        int end_pos = insert_pos + 1;
        while (end_pos != intervals.size())
        {
            //  next_end <= new_end
            if (intervals[end_pos][1] /*next_end*/ <= newInterval[1] /*new_end*/)
            {
                end_pos++;
                continue;
            }

            // next_begin <= new_end
            if (intervals[end_pos][0] /*next_begin*/ <= newInterval[1] /*new_end*/)
            {
                // int merged_begin = intervals[insert_pos][0];
                // int merged_end = intervals[end_pos][1];
                intervals[end_pos][0] = intervals[insert_pos][0];
                intervals.erase(intervals.begin() + insert_pos, intervals.begin() + end_pos);
                return intervals;
            }
            // new_end < next_begin
            else
            {
                end_pos--;
                // int merged_begin = intervals[insert_pos][0];
                // int merged_end = intervals[insert_pos][1];
                intervals[end_pos][0] = intervals[insert_pos][0];
                intervals[end_pos][1] = intervals[insert_pos][1];
                intervals.erase(intervals.begin() + insert_pos, intervals.begin() + end_pos);
                return intervals;
            }
        }

        // [... merged_begin ... new_end]
        intervals.resize(static_cast<size_t>(insert_pos) + 1);
        return intervals;
    }
};

int main()
{
    Solution s;

    std::vector<std::vector<int>> intervals = {{313, 313}, {314, 317}, {318, 320}, {321, 326}, {329, 331}, {332, 334}, {336, 341}};

    std::vector<int> newInterval = {317, 334};

    s.insert(intervals, newInterval);
}

class Solution2
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
    {
        std::vector<std::vector<int>> ans;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] > newEnd)
            {
                ans.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
                return ans;
            }
            else if (intervals[i][1] < newStart)
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
