from typing import List


class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        combination = []

        def rec(index, total):
            if total > target or index >= len(nums):
                if total == target:
                    res.append(combination.copy())
                return None

            combination.append(nums[index])
            rec(index, total + nums[index])
            combination.pop()

            rec(index + 1, total)

        rec(0, 0)
        return res
