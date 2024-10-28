#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> ans{};
        int top = 0;
        int bot = matrix.size();
        int left = 0;
        int right = matrix[0].size();

        while (top < bot && left < right)
        {
            for (int i{left}; i < right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            for (int i{top}; i < bot; i++)
            {
                ans.push_back(matrix[i][right - 1]);
            }
            right--;

            if (top >= bot || left >= right)
                break;

            for (int i{right - 1}; left <= i; i--)
            {
                ans.push_back(matrix[bot - 1][i]);
            }
            left++;

            for (int i{bot - 1}; top <= i; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            bot--;
        }
        return ans;
    }
};
