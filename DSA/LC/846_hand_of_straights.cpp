#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    bool isNStraightHand(std::vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        std::unordered_map<int, int> count{};
        for (int h : hand)
        {
            count[h] += 1;
        }

        std::sort(hand.begin(), hand.end());
        int min_h_index = 0;

        for (int i{}; i < hand.size() / groupSize; ++i)
        {
            int curr_value = hand[min_h_index];
            for (int j{}; j < groupSize; ++j)
            {
                int curr_v_count = count[curr_value];
                if (curr_v_count-- <= 0)
                {
                    return false;
                }
                count[curr_value] = curr_v_count;
                while (curr_v_count <= 0 && min_h_index < hand.size() && hand[min_h_index] == curr_value)
                {
                    min_h_index++;
                }
                curr_value++;
            }
        }

        return true;
    }
};
