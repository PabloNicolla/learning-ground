#include <vector>
#include <queue>
struct Cell
{
    int row{};
    int col{};
};

class Solution
{
public:
    void islandsAndTreasure(std::vector<std::vector<int>> &grid)
    {

        for (int row{}; row < grid.size(); ++row)
        {
            for (int col{}; col < grid[row].size(); ++col)
            {
                if (grid[row][col] == 0)
                {
                    bfs(grid, row, col);
                }
            }
        }
    }

private:
    void bfs(std::vector<std::vector<int>> &grid, int row, int col)
    {
        std::queue<Cell> toVisit{};
        int distance = 1;

        toVisit.push({row + 1, col});
        toVisit.push({row - 1, col});
        toVisit.push({row, col + 1});
        toVisit.push({row, col - 1});

        while (!toVisit.empty())
        {
            int levelSize = toVisit.size();

            for (int i{}; i < levelSize; ++i)
            {
                Cell cell = toVisit.front();
                toVisit.pop();

                if (cell.row < 0 || cell.row >= grid.size() ||
                    cell.col < 0 || cell.col >= grid[0].size() ||
                    // grid[cell.row][cell.col] == -1 || grid[cell.row][cell.col] == 0 ||
                    grid[cell.row][cell.col] <= distance)
                {
                    continue;
                }

                grid[cell.row][cell.col] = distance;
                toVisit.push({cell.row + 1, cell.col});
                toVisit.push({cell.row - 1, cell.col});
                toVisit.push({cell.row, cell.col + 1});
                toVisit.push({cell.row, cell.col - 1});
            }

            distance++;
        }
    }
};