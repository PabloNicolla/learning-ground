#include <vector>
#include <algorithm>

std::vector<int> rotateLeft(int d, std::vector<int> arr)
{
    d %= arr.size();

    if (d == 0)
        return arr;

    std::reverse(arr.begin(), arr.end());
    std::reverse(arr.begin(), arr.end() - d);
    std::reverse(arr.end() - d, arr.end());

    return arr;
}