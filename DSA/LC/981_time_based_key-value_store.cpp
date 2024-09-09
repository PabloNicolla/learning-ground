#include <string>
#include <unordered_map>
#include <vector>

struct Data
{
  int timestamp{};
  std::string value{};
};

class TimeMap
{
  std::unordered_map<std::string, std::vector<Data>> map{};

public:
  TimeMap()
  {
  }

  void set(std::string key, std::string value, int timestamp)
  {
    map[key].push_back({timestamp, value});
  }

  std::string get(std::string key, int timestamp)
  {
    const auto iterator = map.find(key);
    if (iterator == map.end())
    {
      return "";
    }

    const auto &vec = iterator->second;

    if (vec[0].timestamp > timestamp)
    {
      return "";
    }

    int start = 0;
    int end = vec.size() - 1;
    int mid{};
    int prevSmallerTimeIndex{};

    while (start <= end)
    {
      mid = (end - start) / 2 + start;
      if (vec[mid].timestamp == timestamp)
      {
        return vec[mid].value;
      }
      else if (timestamp > vec[mid].timestamp)
      {
        start = mid + 1;
        prevSmallerTimeIndex = mid;
      }
      else
      {
        end = mid - 1;
      }
    }

    return vec[prevSmallerTimeIndex].value;
  }
};