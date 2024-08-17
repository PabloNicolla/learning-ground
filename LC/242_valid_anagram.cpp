#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>

class Solution
{
public:
  bool isAnagram(std::string s, std::string t)
  {
    // std::sort(s.begin(), s.end());
    // std::sort(t.begin(), t.end());
    // return s == t;

    auto s_map = std::unordered_map<char, int>{};
    auto t_map = std::unordered_map<char, int>{};

    if (s.length() != t.length())
    {
      return false;
    }

    for (const auto c : s)
    {
      auto it = s_map.find(c);
      if (it == s_map.end())
      {
        s_map[c] = 1;
      }
      else
      {
        s_map[c]++;
      }
    }

    for (const auto c : t)
    {
      const auto it = t_map.find(c);
      if (it == t_map.end())
      {
        t_map[c] = 1;
      }
      else
      {
        t_map[c] = ++t_map[c];
      }
    }

    if (t_map.size() != s_map.size())
    {
      return false;
    }

    for (const auto &pair : s_map)
    {
      auto const it = t_map.find(pair.first);
      if (it == t_map.end() || t_map[pair.first] != pair.second)
      {
        return false;
      }
    }
    return true;
  }
};
