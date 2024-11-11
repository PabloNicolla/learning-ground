#include <vector>
#include <unordered_set>

class Solution1
{
public:
    bool mergeTriplets(std::vector<std::vector<int>> &triplets, std::vector<int> &target)
    {

        bool res1 = (target[0] == triplets[0][0]);
        bool res2 = (target[1] == triplets[0][1]);
        bool res3 = (target[2] == triplets[0][2]);

        for (int i = 1; i < triplets.size(); i++)
        {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2])
            {
                res1 |= (target[0] == triplets[i][0]);
                res2 |= (target[1] == triplets[i][1]);
                res3 |= (target[2] == triplets[i][2]);
            }
        }
        return res1 && res2 && res3;
    }
};

class Solution2
{
public:
    bool mergeTriplets(std::vector<std::vector<int>> &triplets, std::vector<int> &target)
    {
        std::unordered_set<int> good{};
        int n = target.size();

        for (auto vec : triplets)
        {
            if (vec[0] <= target[0] &&
                vec[1] <= target[1] &&
                vec[2] <= target[2])
            {
                for (int i{}; i < n; ++i)
                {
                    if (target[i] == vec[i])
                    {
                        good.insert(i);
                    }
                }
            }
        }

        return good.size() == n;
    }
};
