#include <queue>
#include <unordered_map>
#include <vector>

struct IdleTask
{
  int remainingTaks{};
  int idleUpTo{};
};

class Solution
{
public:
  int leastInterval(std::vector<char> &tasks, int n)
  {
    std::deque<IdleTask> idleTasks{};
    std::priority_queue<int> scheduler{};
    std::unordered_map<char, int> counter{};
    int time{};

    for (const char task : tasks)
    {
      ++counter[task];
    }

    for (const auto &[task, count] : counter)
    {
      scheduler.push(count);
    }

    while (!idleTasks.empty() || !scheduler.empty())
    {
      if (!scheduler.empty())
      {
        const auto topTask = scheduler.top();
        if (topTask > 1)
        {
          idleTasks.push_back({topTask - 1, time + n});
        }
        scheduler.pop();
      }
      if (!idleTasks.empty() && idleTasks[0].idleUpTo == time)
      {
        scheduler.push(idleTasks[0].remainingTaks);
        idleTasks.pop_front();
      }
      ++time;
    }
    return time;
  }
};

// struct Task
// {
//   int priority{0};
//   char type{'0'};

//   constexpr bool operator<(const Task &other) const
//   {
//     return priority < other.priority;
//   }

//   constexpr bool operator>(const Task &other) const
//   {
//     return priority > other.priority;
//   }
// };

// class Solution2
// {
// public:
//   int leastInterval(const std::vector<char> &tasks, int n)
//   {
//     std::priority_queue<Task, std::vector<Task>, std::greater<Task>> scheduler{};
//     std::unordered_map<char, int> cachedTasks{};

//     int currentPriority{0};
//     int i{};

//     while (i < tasks.size())
//     {
//       if (!scheduler.empty() && scheduler.top().priority <= currentPriority)
//       {
//         scheduler.pop();
//         currentPriority++;
//         continue;
//       }
//       const auto find = cachedTasks.find(tasks[i]);
//       if (find == cachedTasks.end())
//       {
//         scheduler.push({currentPriority, tasks[i]});
//         cachedTasks[tasks[i]] = currentPriority + n + 1;
//       }
//       else
//       {
//         scheduler.push({cachedTasks[tasks[i]], tasks[i]});
//         cachedTasks[tasks[i]] += n + 1;
//       }
//       ++i;
//     }

//     while (scheduler.size() > 1)
//     {
//       scheduler.pop();
//     }

//     return scheduler.empty() ? currentPriority : scheduler.top().priority + 1;
//   }
// };