#include <stdbool.h>
bool searchRow(int *matrix, int rowSize, int target);

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
  int topRow = 0;
  int botRow = matrixSize - 1;
  int midRow = 0;

  while (topRow <= botRow)
  {
    midRow = (botRow - topRow) / 2 + topRow;
    int fRowValue = matrix[midRow][0];
    int lRowValue = matrix[midRow][matrixColSize[midRow] - 1];
    if (fRowValue <= target && target <= lRowValue)
    {
      return searchRow(matrix[midRow], matrixColSize[midRow], target);
    }
    else if (target < fRowValue)
    {
      botRow = midRow - 1;
    }
    else
    {
      topRow = midRow + 1;
    }
  }

  return false;
}

bool searchRow(int *matrix, int rowSize, int target)
{
  int left = 0;
  int right = rowSize - 1;
  int mid = 0;

  while (left <= right)
  {
    mid = (right - left) / 2 + left;
    int cellValue = matrix[mid];
    if (cellValue == target)
    {
      return true;
    }
    else if (target < cellValue)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return false;
}
