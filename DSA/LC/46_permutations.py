
from typing import List


class Solution2:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [[nums[0]]]

        permutations = self.permute(nums[1::])

        original_len = len(permutations)

        for i in range(original_len):

            original_len2 = len(permutations[i])

            for j in range(0, original_len2):
                copy = permutations[i].copy()
                copy.insert(j, nums[0])
                permutations.append(copy)

            permutations[i].append(nums[0])

        return permutations


class Solution3:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def rec(subSet, remainingOptions):
            if len(remainingOptions) == 0:
                res.append(subSet)
                return

            for i in range(0, len(remainingOptions)):
                copy = subSet.copy()
                copy.append(remainingOptions[i])
                rec(copy, remainingOptions[0:i:] + remainingOptions[i + 1:len(remainingOptions):])

        rec([], nums)
        return res
