#include <vector>

class Solution
{
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int x_size = grid.size();
        int y_size = grid[0].size();
        int ans = 0;

        for (int x = 0; x < x_size; ++x)
        {
            for (int y = 0; y < y_size; ++y)
            {
                if (grid[x][y] == 1)
                {
                    ans = std::max(ans, dfs(grid, x, y));
                }
            }
        }

        return ans;
    }

private:
    int dfs(std::vector<std::vector<int>> &grid, int x, int y)
    {
        std::vector<std::pair<int, int>> stack{};
        int x_size = grid.size();
        int y_size = grid[0].size();
        int land_count{};

        stack.push_back({x, y});

        while (!stack.empty())
        {
            const std::pair<int, int> curr = stack.back();
            stack.pop_back();

            if (curr.first < 0 || curr.first >= x_size || curr.second < 0 || curr.second >= y_size || grid[curr.first][curr.second] != 1)
                continue;

            grid[curr.first][curr.second] = 0; // Mark as visited
            ++land_count;

            // Check adjacent cells
            stack.push_back({curr.first - 1, curr.second});
            stack.push_back({curr.first + 1, curr.second});
            stack.push_back({curr.first, curr.second - 1});
            stack.push_back({curr.first, curr.second + 1});
        }
        return land_count;
    }
};