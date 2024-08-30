#include <queue>
#include <vector>

class Solution
{
public:
  int findKthLargest(std::vector<int> &nums, int k)
  {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq{};

    for (const int num : nums)
    {
      pq.push(num);
      if (pq.size() > k)
        pq.pop();
    }

    return pq.top();
  }
};