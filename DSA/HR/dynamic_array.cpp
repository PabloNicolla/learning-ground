#include <vector>

std::vector<int> dynamicArray(int n, std::vector<std::vector<int>> queries)
{
    int last_answer{};
    std::vector<int> answers{};
    std::vector<std::vector<int>> arr(n);

    for (const auto &inner : queries)
    {
        int x = inner[1];
        int y = inner[2];
        int index = (x ^ last_answer) % n;

        if (inner[0] == 1)
        {
            arr[index].push_back(y);
        }
        else if (inner[0] == 2)
        {
            last_answer = arr[index][y % arr[index].size()];
            answers.push_back(last_answer);
        }
    }

    return answers;
}
