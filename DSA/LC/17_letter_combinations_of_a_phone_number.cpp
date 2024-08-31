#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::vector<std::string> ans{};
        const std::unordered_map<char, std::vector<char>> phone_map = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}};
        std::string combination{};

        const std::function<void(const int)> rec = [&](const int index) -> void
        {
            if (index >= digits.size())
            {
                if (!combination.empty())
                {
                    ans.push_back(combination);
                }
                return;
            }

            for (char c : phone_map.at(digits[index]))
            {
                combination.push_back(c);
                rec(index + 1);
                combination.pop_back();
            }
        };

        rec(0);
        return ans;
    }
};