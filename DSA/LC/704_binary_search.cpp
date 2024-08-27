#include <vector>
class Solution
{
public:
  int search(std::vector<int> &nums, int target)
  {
    int left = 0;
    int right = nums.size() - 1;
    int mid{};

    while (left <= right)
    {
      mid = (right - left) / 2 + left;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return -1;
  }
};
