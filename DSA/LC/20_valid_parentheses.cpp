#include <deque>
#include <string>

class Solution
{
public:
  bool isValid(std::string s)
  {
    std::deque<char> stack{};

    for (const char c : s)
    {
      if (c == '(' || c == '[' || c == '{')
      {
        stack.push_back(c);
      }
      else if (c == ')' || c == ']' || c == '}')
      {
        if (stack.empty())
        {
          return false;
        }
        const char back = stack.back();
        if ((back == '(' && c != ')') || (back == '[' && c != ']') || (back == '{' && c != '}'))
        {
          return false;
        }
        stack.pop_back();
      }
    }

    return stack.empty();
  }
};