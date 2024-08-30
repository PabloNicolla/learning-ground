#include <vector>

class Solution
{
private:
  void Solve(int i, std::vector<int> &nums, std::vector<int> &temp, std::vector<std::vector<int>> &ans)
  {
    if (i == nums.size())
    {
      ans.push_back(temp);
      return;
    }

    temp.push_back(nums[i]);
    Solve(i + 1, nums, temp, ans);

    temp.pop_back();
    Solve(i + 1, nums, temp, ans);
  }

public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums)
  {
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;
    Solve(0, nums, temp, ans);
    return ans;
  }
};