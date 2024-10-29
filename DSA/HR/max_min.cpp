
#include <deque>
#include <vector>
#include <limits>
#include <algorithm>
#include <array>

int maxMin(int k, std::vector<int> arr)
{
    if (arr.size() < k)
        return -1;

    std::sort(arr.begin(), arr.end());

    int min_unfair = std::numeric_limits<int>::max();
    // [(value, id), ...]
    std::deque<std::array<int, 2>> max_d{};
    // [(value, id), ...]
    std::deque<std::array<int, 2>> min_d{};

    for (int i{}; i < k; ++i)
    {
        int num = arr[i];

        while (!max_d.empty() && num > max_d.back()[0])
        {
            max_d.pop_back();
        }
        while (!min_d.empty() && num < min_d.back()[0])
        {
            min_d.pop_back();
        }

        max_d.push_back({num, i});
        min_d.push_back({num, i});
    }

    min_unfair = max_d[0][0] - min_d[0][0];

    for (int i{k}; i < arr.size(); ++i)
    {
        int num = arr[i];

        while (!max_d.empty() && num > max_d.back()[0])
        {
            max_d.pop_back();
        }
        while (!min_d.empty() && num < min_d.back()[0])
        {
            min_d.pop_back();
        }

        max_d.push_back({num, i});
        min_d.push_back({num, i});

        if (max_d[0][1] <= i - k)
        {
            max_d.pop_front();
        }
        if (min_d[0][1] <= i - k)
        {
            min_d.pop_front();
        }

        min_unfair = std::min(min_unfair, max_d[0][0] - min_d[0][0]);
    }
    return min_unfair;
}
