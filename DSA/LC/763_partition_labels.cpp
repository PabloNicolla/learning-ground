#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

class Solution1
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        std::vector<int> answer{};

        // Range start...end
        int start{};
        int end{};

        while (end < s.size())
        {
            std::unordered_set<char> chars_in{};   // chars in the substring that cannot be elsewhere
            std::unordered_set<char> chars_temp{}; // chars elsewhere
            chars_in.insert(s[end]);
            int curr{end + 1};
            while (curr < s.size())
            {
                chars_temp.insert(s[curr]);
                // if char in chars_in. Merge sets and update end range
                if (std::find(chars_in.begin(), chars_in.end(), s[curr]) != chars_in.end())
                {
                    chars_in.insert(chars_temp.begin(), chars_temp.end());
                    chars_temp.clear();
                    end = curr;
                }
                curr++;
            }
            // add range length to asnwer
            answer.push_back(end - start + 1);
            end++;
            start = end;
        }

        return answer;
    }
};
