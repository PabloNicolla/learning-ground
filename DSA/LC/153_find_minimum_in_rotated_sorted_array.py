from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        mid = 0

        while (left <= right):
            mid = (left + right) // 2
            if (nums[left] > nums[right]):
                if (nums[mid] > nums[right]):
                    left = mid + 1
                else:
                    right = mid
            else:
                return nums[left]
