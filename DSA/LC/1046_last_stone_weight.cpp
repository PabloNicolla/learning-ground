#include <vector>
#include <queue>

class Solution
{
public:
    int lastStoneWeight(std::vector<int> &stones)
    {
        std::priority_queue<int> pq{};
        for (const int stone : stones)
        {
            pq.push(stone);
        }

        while (pq.size() > 1)
        {
            const int stone1 = pq.top();
            pq.pop();
            const int stone2 = pq.top();
            pq.pop();
            if ((stone1 - stone2) != 0)
                pq.push(stone1 - stone2);
        }

        return pq.empty() ? 0 : pq.top();
    }
};