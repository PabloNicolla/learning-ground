#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    bool wordBreak(std::string s, const std::vector<std::string> &wordDict)
    {
        std::vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size(); i >= 0; --i)
        {
            for (const auto &word : wordDict)
            {
                if (i + word.size() <= s.size() && compare(s, word, i, i + word.size()))
                {
                    dp[i] = dp[i + word.size()];
                }
                if (dp[i])
                {
                    break;
                }
            }
        }

        return dp[0];
    }

    bool compare(const std::string &s1, const std::string &s2, int s1_start, int s1_end)
    {
        for (int i{s1_start}; i < s1_end; ++i)
        {
            if (s1[i] != s2[i - s1_start])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s{};
    std::vector<int> coins{1, 5, 10};
    auto a = s.wordBreak("leetcode", {"leet", "code"});

    std::cout << a << "\n\n";
    return 0;
}