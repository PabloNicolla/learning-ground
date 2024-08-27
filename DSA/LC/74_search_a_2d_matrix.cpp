#include <vector>

class Solution
{
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
  {
    int topRow = 0;
    int botRow = matrix.size() - 1;
    int midRow{};

    while (topRow <= botRow)
    {
      midRow = (botRow - topRow) / 2 + topRow;
      int firstCell = matrix[midRow][0];
      if (firstCell == target)
      {
        return true;
      }
      else if (target < firstCell)
      {
        botRow = midRow - 1;
      }
      else
      {
        topRow = midRow + 1;
      }
    }

    if (botRow == -1)
    {
      return false;
    }
    midRow = botRow;

    int leftCol = 0;
    int rightCol = matrix[midRow].size() - 1;
    int midCol{};

    while (leftCol <= rightCol)
    {
      midCol = (rightCol - leftCol) / 2 + leftCol;
      int cell = matrix[midRow][midCol];
      if (cell == target)
      {
        return true;
      }
      else if (target < cell)
      {
        rightCol = midCol - 1;
      }
      else
      {
        leftCol = midCol + 1;
      }
    }

    return false;
  }
};
