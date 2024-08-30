#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int diagonalDifference(vector<vector<int>> arr)
{
    int n = arr.size();
    int primary_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;

    for (int i = 0; i < n; i++)
    {
        primary_diagonal_sum += arr[i][i];
        secondary_diagonal_sum += arr[i][n - 1 - i];
    }

    int difference = abs(primary_diagonal_sum - secondary_diagonal_sum);

    return difference;
}