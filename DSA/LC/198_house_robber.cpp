#include <vector>
#include <algorithm>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int prevBest{};
        int currBest{};

        // [prevBest, currBest, num, ...]
        for (int num : nums)
        {
            int temp = std::max(num + prevBest, currBest);
            prevBest = currBest;
            currBest = temp;
        }

        return currBest;
    }
};