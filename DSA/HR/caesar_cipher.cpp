#include <string>

std::string caesarCipher(const std::string &s, int k)
{
    k %= 26; // Reduce k to the effective rotation within the alphabet length
    std::string ans;
    ans.reserve(s.size()); // Reserve space to avoid repeated allocations

    // Lambda function to shift character by `k` within the alphabet bounds
    auto shiftChar = [k](char base, char c)
    {
        return base + (c - base + k) % 26;
    };

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            ans.push_back(shiftChar('a', c));
        }
        else if (c >= 'A' && c <= 'Z')
        {
            ans.push_back(shiftChar('A', c));
        }
        else
        {
            ans.push_back(c); // Non-alphabet characters remain unchanged
        }
    }
    return ans;
}

std::string caesarCipher_2(std::string s, int k)
{
    k %= 26;

    std::string ans{};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            int diff = (c + k);

            if (diff > 'z')
            {
                diff %= ('z' + 1);
                ans.push_back('a' + diff);
            }
            else
            {
                ans.push_back(diff);
            }
        }
        else if (c >= 'A' && c <= 'Z')
        {
            int diff = (c + k);

            if (diff > 'Z')
            {
                diff %= ('Z' + 1);
                ans.push_back('A' + diff);
            }
            else
            {
                ans.push_back(diff);
            }
        }
        else
        {
            ans.push_back(c);
        }
    }
    return ans;
}
