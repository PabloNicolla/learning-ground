#include <string>

class Solution
{
public:
  int characterReplacement(std::string s, int k)
  {
    int max = 0;

    for (int i = 0; i < s.size(); ++i)
    {
      int remaining = k;
      int lenght = 1;
      for (int j = i + 1; j < s.size(); ++j)
      {
        lenght++;
        if (s[i] == s[j])
        {
          continue;
        }
        else if (remaining > 0)
        {
          remaining--;
        }
        else
        {
          lenght--;
          break;
        }
      }

      for (int j = i - 1; j >= 0 && remaining > 0; --j, --remaining)
      {
        lenght++;
      }

      if (lenght > max)
      {
        max = lenght;
      }
    }

    return max;
  }
};