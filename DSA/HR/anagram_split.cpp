#include <string>
#include <unordered_map>
#include <algorithm>

int anagram(const std::string &s)
{
    if (s.size() % 2 == 1)
        return -1;

    int mid = s.size() / 2;
    std::unordered_map<char, int> count;

    // Count occurrences in the first half
    for (int i = 0; i < mid; ++i)
    {
        count[s[i]]++;
    }

    // Subtract occurrences in the second half
    for (int i = mid; i < s.size(); ++i)
    {
        count[s[i]]--;
    }

    // Calculate the total adjustments needed to match halves
    int ans = 0;
    for (const auto &pair : count)
    {
        if (pair.second > 0)
            ans += pair.second;
    }

    return ans;
}
