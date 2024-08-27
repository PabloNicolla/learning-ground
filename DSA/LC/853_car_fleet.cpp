#include <vector>
#include <algorithm>

class Solution
{
public:
  int carFleet(int target, std::vector<int> &position, std::vector<int> &speed)
  {
    std::vector<std::pair<int, int>> carsAndSpeed{};

    // Slow sort ;-;
    // for (int i = 0; i < position.size(); ++i) {
    //  carsAndSpeed.push_back({});
    //  int j = i - 1;
    //  while (j >= 0 && carsAndSpeed[j].first < position[i]) {
    //    carsAndSpeed[j + 1] = carsAndSpeed[j];
    //    --j;
    //  }
    //  carsAndSpeed[j + 1] = { position[i], speed[i] };
    //}

    for (int i = 0; i < position.size(); ++i)
    {
      carsAndSpeed.push_back({position[i], speed[i]});
    }

    std::sort(carsAndSpeed.begin(), carsAndSpeed.end(), [](const std::pair<int, int> &car1, const std::pair<int, int> &car2) -> bool
              { return car1.first > car2.first; });

    double maxTime = 0;
    int fleetCounter = 0;

    for (const auto pair : carsAndSpeed)
    {
      double carTime = ((target - pair.first) * 1.0 / pair.second);
      if (carTime > maxTime)
      {
        maxTime = carTime;
        fleetCounter++;
      }
    }

    return fleetCounter;
  }
};