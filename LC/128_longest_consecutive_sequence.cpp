#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>

class Solution
{
public:
  int longestConsecutive(std::vector<int> &nums)
  {
    if (nums.size() == 0)
    {
      return 0;
    }

    std::sort(nums.begin(), nums.end());

    int longestSeqFound = 1;
    int currentSeqLen = 1;
    std::vector<int>::iterator currEnd{nums.begin()};
    std::vector<int>::iterator prevValueCache{nums.end()};

    while (currEnd != nums.end())
    {
      int prevValue = *currEnd;

      ++currEnd;
      if (currEnd == nums.end())
      {
        break;
      }
      else if (*currEnd == prevValue)
      {
        continue;
      }
      else if (*currEnd == ++prevValue)
      {
        ++currentSeqLen;
        if (currentSeqLen > longestSeqFound)
        {
          longestSeqFound = currentSeqLen;
        }
      }
      else
      {
        currentSeqLen = 1;
      }
    }

    return longestSeqFound;
  }
};