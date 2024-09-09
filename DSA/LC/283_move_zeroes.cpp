#include <vector>

class Solution
{
public:
  void moveZeroes(std::vector<int> &nums)
  {
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
      {
        nums[lastNonZeroFoundAt++] = nums[i];
      }
    }
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
    {
      nums[i] = 0;
    }
  }
};