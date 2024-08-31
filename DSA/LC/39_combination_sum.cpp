#include <vector>
#include <functional>

class Solution
{
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
  {
    std::vector<std::vector<int>> res{};

    std::vector<int> combination{};

    const std::function<void(const int, const int)> rec = [&](const int index, const int sum)
    {
      if (index >= candidates.size() || sum > target)
      {
        if (sum == target)
          res.push_back(combination);
        return;
      }

      combination.push_back(candidates[index]);
      rec(index, sum + candidates[index]);
      combination.pop_back();

      rec(index + 1, sum);
    };

    rec(0, 0);
    return res;
  }
};