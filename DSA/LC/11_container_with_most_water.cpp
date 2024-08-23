#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>

class Solution
{
public:
  int maxArea(std::vector<int> &heights)
  {
    int maxVol = 0;
    int head = 0;
    int tail = heights.size() - 1;

    while (head < tail)
    {
      maxVol = std::max(maxVol, std::min(heights[tail], heights[head]) * (tail - head));
      if (heights[tail] < heights[head])
      {
        tail--;
      }
      else if (heights[tail] == heights[head])
      {
        do
        {
          if (heights[tail - 1] > heights[head + 1])
          {
            tail--;
          }
          else
          {
            head++;
          }
        } while (head < tail && heights[tail] == heights[head]);
      }
      else
      {
        head++;
      }
    }
    return maxVol;
  }
};