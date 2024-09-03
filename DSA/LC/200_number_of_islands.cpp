#include <vector>
#include <unordered_set>

class Solution1
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }

private:
    void dfs(std::vector<std::vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::pair<int, int>> stack{};

        stack.push_back({i, j});

        while (!stack.empty())
        {
            const std::pair<int, int> curr = stack.back();
            stack.pop_back();

            if (curr.first < 0 || curr.first >= m || curr.second < 0 || curr.second >= n || grid[curr.first][curr.second] != '1')
                continue;

            grid[curr.first][curr.second] = '0'; // Mark as visited

            // Check adjacent cells
            stack.push_back({curr.first - 1, curr.second});
            stack.push_back({curr.first + 1, curr.second});
            stack.push_back({curr.first, curr.second - 1});
            stack.push_back({curr.first, curr.second + 1});
        }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////// Solution 3
class Solution3
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }

private:
    void dfs(std::vector<std::vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;

        grid[i][j] = '0'; // Mark as visited

        // Check adjacent cells
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////// Solution 2
struct Point
{
    int x{};
    int y{};

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

struct PointHash
{
    std::size_t operator()(const Point &p) const
    {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

class Solution2
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int ans{};
        std::unordered_set<Point, PointHash> visited{};
        std::vector<Point> stack{};
        const std::vector<Point> directions{
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
        };

        for (int x{}; x < grid.size(); ++x)
        {
            for (int y{}; y < grid[x].size(); ++y)
            {
                Point pos{x, y};

                if (grid[x][y] == '1' && visited.find(pos) == visited.end())
                {
                    stack.push_back(pos);
                    visited.insert(pos);
                    ans++;

                    while (!stack.empty())
                    {
                        Point curr = stack.back();
                        stack.pop_back();

                        for (const auto &direction : directions)
                        {
                            int new_x = curr.x + direction.x;
                            int new_y = curr.y + direction.y;
                            Point new_point{new_x, new_y};
                            if (
                                0 <= new_x && new_x < grid.size() &&
                                0 <= new_y && new_y < grid[curr.x].size() &&
                                grid[new_x][new_y] == '1' &&
                                visited.find(new_point) == visited.end())
                            {
                                stack.push_back(new_point);
                                visited.insert(new_point);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};