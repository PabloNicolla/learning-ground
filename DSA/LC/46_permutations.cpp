#include <iostream>
#include <vector>

class Solution1
{
public:
    std::vector<std::vector<int>> permute(const std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans{{}};
        for (int num : nums)
        {
            std::vector<std::vector<int>> new_ans;
            for (const auto &perm : ans)
            {
                for (size_t i = 0; i <= perm.size(); ++i)
                {
                    std::vector<int> new_perm(perm);
                    new_perm.insert(new_perm.begin() + i, num);
                    new_ans.push_back(std::move(new_perm));
                }
            }
            ans = std::move(new_ans);
        }
        return ans;
    }
};

class Solution2
{
public:
    std::vector<std::vector<int>> permute(const std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans{};
        ans.push_back({nums[0]});
        for (int num_index = 1; num_index < nums.size(); num_index++)
        {
            int cur_ans_size = ans.size();
            for (int ans_index = 0; ans_index < cur_ans_size; ans_index++)
            {
                int cur_perm_size = ans[ans_index].size();
                for (int perm_index = 0; perm_index < cur_perm_size; perm_index++)
                {
                    std::vector<int> copy{};
                    for (int copy_index = 0; copy_index < cur_perm_size; copy_index++)
                    {
                        if (copy_index == perm_index)
                            copy.push_back(nums[num_index]);
                        copy.push_back(ans[ans_index][copy_index]);
                    }
                    ans.emplace_back(std::move(copy));
                }
                ans[ans_index].push_back(nums[num_index]);
            }
        }
        return ans;
    }
};
