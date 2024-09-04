#include <vector>
#include <functional>

class Solution
{
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights)
    {
        std::vector<std::vector<int>> ans{};
        std::vector<std::vector<bool>> canReachPacific{};
        std::vector<std::vector<bool>> canReachAtlantic{};
        std::vector<std::pair<int, int>> pacificStack{};
        std::vector<std::pair<int, int>> atlanticStack{};

        for (int row{}; row < heights.size(); ++row)
        {
            canReachPacific.push_back({});
            canReachAtlantic.push_back({});
            for (int col{}; col < heights[row].size(); ++col)
            {
                if (row == 0 || col == 0)
                {
                    canReachPacific[row].push_back(true);
                    pacificStack.push_back({row, col});
                }
                else
                {
                    canReachPacific[row].push_back(false);
                }

                if (row == heights.size() - 1 || col == heights[row].size() - 1)
                {
                    canReachAtlantic[row].push_back(true);
                    atlanticStack.push_back({row, col});
                }
                else
                {
                    canReachAtlantic[row].push_back(false);
                }
            }
        }

        std::vector<std::vector<int>> directions{
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };

        std::function<void(std::vector<std::pair<int, int>> &, std::vector<std::vector<bool>> &)> calculateReach =
            [&](std::vector<std::pair<int, int>> &stack, std::vector<std::vector<bool>> &reachGrid)
        {
            while (!stack.empty())
            {
                auto cell = stack.back();
                stack.pop_back();

                for (auto d : directions)
                {
                    int row = cell.first + d[0];
                    int col = cell.second + d[1];

                    if (row < 0 || row >= heights.size() ||
                        col < 0 || col >= heights[0].size() ||
                        heights[row][col] < heights[cell.first][cell.second] ||
                        reachGrid[row][col] == true)
                    {
                        continue;
                    }

                    reachGrid[row][col] = true;
                    stack.push_back({row, col});
                }
            }
        };

        calculateReach(pacificStack, canReachPacific);
        calculateReach(atlanticStack, canReachAtlantic);

        for (int row{}; row < heights.size(); ++row)
        {
            for (int col{}; col < heights[row].size(); ++col)
            {
                if (canReachAtlantic[row][col] && canReachPacific[row][col])
                {
                    ans.push_back({row, col});
                }
            }
        }

        return ans;
    }
};