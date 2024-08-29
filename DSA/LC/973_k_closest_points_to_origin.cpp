#include <vector>
#include <queue>
#include <cmath>

struct Distance_And_Point
{
  double distance{};
  int x{};
  int y{};

  constexpr bool operator>(const Distance_And_Point &other) const
  {
    return distance > other.distance;
  }
  constexpr bool operator<(const Distance_And_Point &other) const
  {
    return !this->operator<(other);
  }
};

class Solution
{
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
  {
    std::priority_queue<Distance_And_Point, std::vector<Distance_And_Point>, std::greater<Distance_And_Point>> pq{};

    for (const std::vector<int> &point : points)
    {
      const double distance = std::sqrt(
          std::pow(static_cast<double>(0 - point[0]), 2) + std::pow(static_cast<double>(0 - point[1]), 2));
      pq.push({distance, point[0], point[1]});
    }

    std::vector<std::vector<int>> ans{};

    for (int i{}; i < k; ++i)
    {
      ans.push_back({pq.top().x, pq.top().y});
      pq.pop();
    }

    return ans;
  }
};