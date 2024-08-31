#include <vector>
#include <algorithm>
#include <functional>

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        std::vector<std::vector<int>> res{};

        std::sort(candidates.begin(), candidates.end());

        std::vector<int> combination{};

        const std::function<void(int, const int)> rec = [&](int index, const int sum)
        {
            if (index >= candidates.size() || sum > target)
            {
                if (sum == target)
                    res.push_back(combination);
                return;
            }

            combination.push_back(candidates[index]);
            rec(index + 1, sum + candidates[index]);
            combination.pop_back();

            while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1])
            {
                index++;
            }

            rec(index + 1, sum);
        };

        rec(0, 0);
        return res;
    }
};

class Solution2
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(std::vector<int> &candidates, int target, int start, std::vector<int> &current, std::vector<std::vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            if (candidates[i] > target)
            {
                break;
            }

            current.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
};