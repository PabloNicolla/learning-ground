#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>

class Solution
{
public:
    /**
     * @brief Finds the minimum interval size containing each query point
     *
     * @param intervals Vector of intervals where each interval is [start, end]
     * @param queries Vector of query points
     * @return Vector where answer[i] is the size of smallest interval containing queries[i],
     *         or -1 if no interval contains the query point
     *
     * Time Complexity: O((N + Q) * log(N + Q)) where N is number of intervals and Q is number of queries
     * Space Complexity: O(N + Q)
     */
    std::vector<int> minInterval(std::vector<std::vector<int>> &intervals,
                                 std::vector<int> &queries)
    {
        // Pair each query with its original index and sort
        std::vector<std::pair<int, int>> queriesWithIndex;
        queriesWithIndex.reserve(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            queriesWithIndex.emplace_back(queries[i], i);
        }
        std::sort(queriesWithIndex.begin(), queriesWithIndex.end());

        // Sort intervals by start time
        std::sort(intervals.begin(), intervals.end());

        // Min heap to store {interval_size, end_time}
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<>>
            minHeap;

        std::vector<int> result(queries.size(), -1);
        int intervalIdx = 0;

        // Process each query in sorted order
        for (const auto &[queryTime, originalIndex] : queriesWithIndex)
        {
            // Add all intervals that start before or at query time
            while (intervalIdx < intervals.size() &&
                   intervals[intervalIdx][0] <= queryTime)
            {
                int start = intervals[intervalIdx][0];
                int end = intervals[intervalIdx][1];
                int size = end - start + 1;
                minHeap.push({size, end});
                intervalIdx++;
            }

            // Remove intervals that end before query time
            while (!minHeap.empty() && minHeap.top().second < queryTime)
            {
                minHeap.pop();
            }

            // If we have a valid interval, it's the smallest one containing query
            if (!minHeap.empty())
            {
                result[originalIndex] = minHeap.top().first;
            }
        }

        return result;
    }
};

class Solution2
{
public:
    std::vector<int> minInterval(std::vector<std::vector<int>> &intervals, std::vector<int> &queries)
    {
        std::sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs)
                  { return (lhs[1] - lhs[0]) < (rhs[1] - rhs[0]); });

        std::vector<int> ans(queries.size(), -1);
        std::unordered_map<int, int> map{};

        for (int i{}; i < queries.size(); ++i)
        {
            int q = queries[i];
            for (const auto &inter : intervals)
            {
                if (inter[0] <= q && q <= inter[1])
                {
                    ans[i] = (inter[1] - inter[0] + 1);
                    break;
                }
            }
        }

        return ans;
    }
};
