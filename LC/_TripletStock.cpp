#include <vector>
#include <unordered_map>

class Solution
{
public:
  int tripletStock(std::vector<int> prices, int d)
  {
    int count{0};
    std::unordered_map<int, int> freq{};

    if (prices.size() <= 2)
    {
      return 0;
    }

    freq[((prices[0] + prices[1]) % d)] = 1;

    for (size_t i{2}; i < prices.size(); ++i)
    {
      const auto it = freq.find(d - (prices[i] % d));
      if (it != freq.end())
      {
        count += it->second;
      }

      for (size_t j{0}; j < i; ++j)
      {
        const auto newFreq = (prices[i] + prices[j]) % d;
        const auto hasFreq = freq.find(newFreq);
        if (hasFreq != freq.end())
        {
          hasFreq->second++;
        }
        else
        {
          freq[newFreq] = 1;
        }
      }
    }
    return count;
  }
};