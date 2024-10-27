#include <iostream>
#include <string>
#include <regex>
#include <optional>

class Solution
{
public:
    std::string validIPAddress(const std::string &queryIP)
    {
        if (validIPv4(queryIP))
        {
            return "IPv4";
        }
        if (validIPv6(queryIP))
        {
            return "IPv6";
        }
        return "Neither";
    }

    bool validIPv4(const std::string &str)
    {
        std::regex rgx(R"(^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$)");

        std::smatch sm;
        if (std::regex_match(str, sm, rgx))
        { // Use regex_match for exact match
            for (size_t i = 1; i < sm.size(); i++)
            { // Start from 1 to skip the full match
                int block = std::stoi(sm[i]);
                // Check if block is out of range or has leading zeros
                if (block < 0 || block > 255 || (sm[i].length() > 1 && sm[i].str()[0] == '0'))
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool validIPv6(const std::string &str)
    {
        std::regex rgx(R"(^([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4})$)");

        std::smatch sm;
        // Use regex_match for exact match
        if (std::regex_match(str, sm, rgx))
        {
            return true; // Valid if we matched all 8 blocks
        }
        return false;
    }
};

using namespace std;

class Solution1
{
public:
    string validIPAddress(string queryIP)
    {
        if (queryIP.find('.') != string::npos)
        {
            if (verifyIpv4(queryIP))
            {
                return "IPv4";
            }
        }
        if (queryIP.find(':') != string::npos)
        {
            if (verifyIpv6(queryIP))
            {
                return "IPv6";
            }
        }
        return "Neither";
    }

private:
    // return number, idx of next colon
    optional<pair<int, int>> extractNumber(const string &str, int beginIdx)
    {
        size_t colonIdx = str.find('.', beginIdx);
        // if (colonIdx - (beginIdx - 1) - 1 == 0) {
        //     return {};  // no numbers in between
        // }

        int buffer = 0;
        int end = min(colonIdx, str.size());
        bool leadingZero = false;
        if (beginIdx == end)
        {
            return {}; // no number to iterate
        }

        for (int i = beginIdx; i < end; i++)
        {
            char c = str[i];
            if (!isdigit(c))
            {
                return {};
            }
            else
            {
                if (buffer == 0 && c == '0')
                {
                    if (leadingZero)
                    {
                        // second zero
                        return {};
                    }
                    else
                    {
                        leadingZero = true;
                    }
                }
                else
                {
                    // any other number
                    if (leadingZero)
                    {
                        return {};
                    }
                }
                buffer *= 10;
                buffer += c - '0';
                if (buffer > 255)
                {
                    return {};
                }
            }
        }
        return make_optional<pair<int, int>>(buffer, colonIdx);
    }
    bool verifyIpv4(const string &str)
    {
        int nextBeginning = 0;
        for (int i = 0; i < 3; i++)
        {
            auto res = extractNumber(str, nextBeginning);
            if (!res || res->second == string::npos)
            {
                return false;
            }
            nextBeginning = res->second + 1;
        }
        auto res = extractNumber(str, nextBeginning);
        return res && res->second == string::npos && str.back() != '.';
    }

    bool verifyIpv6(const string &str)
    {
        int prevColon = -1;
        int colonCount = 0;
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (c == ':')
            {
                colonCount++;
                if (colonCount > 7)
                {
                    return false;
                }
                //< 4 digits
                if (i - prevColon - 1 > 4 || i - prevColon - 1 == 0)
                {
                    return false;
                }
                prevColon = i;
            }
            else if (!((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || isdigit(c)))
            {
                return false;
            }
        }
        return str.size() - prevColon - 1 <= 4 && colonCount == 7 && str.back() != ':';
    }
};