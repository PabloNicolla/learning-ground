#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>

class Solution
{
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
  {
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;

    for (auto &str : strs)
    {
      std::string sortedStr = str;
      std::sort(sortedStr.begin(), sortedStr.end());

      anagramMap[sortedStr].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (auto &pair : anagramMap)
    {
      result.push_back(pair.second);
    }

    return result;
  }
};