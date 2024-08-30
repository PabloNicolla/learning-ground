from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        subSet = []
        nums.sort()

        def rec(index):
            if index >= len(nums):
                res.append(subSet.copy())
                return

            subSet.append(nums[index])
            rec(index + 1)

            while index + 1 < len(nums) and nums[index] == nums[index + 1]:
                index += 1

            subSet.pop()
            rec(index + 1)

        rec(0)
        return res
