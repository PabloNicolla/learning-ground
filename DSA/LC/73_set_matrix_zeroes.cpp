#include <vector>
#include <unordered_set>
class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        std::unordered_set<int> rows{};
        std::unordered_set<int> cols{};

        int row_size = matrix.size();
        int col_size = matrix[0].size();

        for (int row{}; row < row_size; ++row)
        {
            for (int col{}; col < col_size; ++col)
            {
                if (matrix[row][col] == 0)
                {
                    rows.insert(row);
                    cols.insert(col);
                }
            }
        }

        for (int row{}; row < row_size; ++row)
        {
            bool foundRow = rows.find(row) != rows.end();
            for (int col{}; col < col_size; ++col)
            {
                if (foundRow)
                {
                    matrix[row][col] = 0;
                }
                else if (cols.find(col) != cols.end())
                {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};
