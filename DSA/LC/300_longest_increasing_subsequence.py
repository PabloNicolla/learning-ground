from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        memo = [0] * len(nums)
        global_max = 0

        for i in range(len(nums)):
            max_found = 0
            for j in range(0, i):
                if nums[j] < nums[i] and max_found < memo[j]:
                    max_found = memo[j]
            memo[i] += max_found + 1
            global_max = max(global_max, memo[i])
        return global_max
