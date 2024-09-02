#include <string>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string max_pal{};
        int max_length{};

        for (int i = 0; i < s.size(); ++i)
        {
            int left = i;
            int right = i;
            // ODD
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if (right - left + 1 > max_length)
                {
                    max_pal = s.substr(left, right - left + 1);
                    max_length = right - left + 1;
                }
                --left;
                ++right;
            }

            left = i;
            right = i + 1;
            // EVEN
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if (right - left + 1 > max_length)
                {
                    max_pal = s.substr(left, right - left + 1);
                    max_length = right - left + 1;
                }
                --left;
                ++right;
            }
        }

        return max_pal;
    }
};
