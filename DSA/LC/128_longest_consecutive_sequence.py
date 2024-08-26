from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        longest = 0

        for n in nums_set:
            if (n - 1) not in nums_set:
                curr_len = 1
                while n + curr_len in nums_set:
                    curr_len += 1
                longest = max(curr_len, longest)
        return longest
