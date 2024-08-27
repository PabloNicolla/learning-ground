#include <deque>

class MinStack
{
  std::deque<int> data{};
  std::deque<int> minMemory{};

public:
  MinStack()
  {
  }

  void push(int val)
  {
    data.push_back(val);
    if (minMemory.empty() || minMemory.back() > val)
    {
      minMemory.push_back(val);
    }
    else
    {
      minMemory.push_back(minMemory.back());
    }
  }

  void pop()
  {
    data.pop_back();
    minMemory.pop_back();
  }

  int top()
  {
    return data.back();
  }

  int getMin()
  {
    return minMemory.back();
  }
};