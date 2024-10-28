#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int size = matrix.size();
        int section_size = size / 2;
        for (int i{}; i < section_size; ++i)
        {
            int inner_size = size - 1 - i;
            for (int j{i}; j < inner_size; ++j)
            {
                auto &top_left = matrix[i][j];
                auto &top_right = matrix[j][size - 1 - i];
                auto &bot_right = matrix[size - 1 - i][size - 1 - j];
                auto &bot_left = matrix[size - 1 - j][i];

                int temp = bot_left;

                bot_left = bot_right;
                bot_right = top_right;
                top_right = top_left;
                top_left = temp;
            }
        }
    }
};