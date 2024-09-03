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


class Solution2:
    def lengthOfLIS(self, nums: List[int]) -> int:
        LIS = [1] * len(nums)

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    LIS[i] = max(LIS[i], 1 + LIS[j])
        return max(LIS)
