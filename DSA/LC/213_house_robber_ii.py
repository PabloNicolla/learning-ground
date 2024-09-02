class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        return max(
            self.helper(nums, 0, len(nums) - 1),
            self.helper(nums, 1, len(nums))
        )

    def helper(self, nums: List[int], start, end):
        prevMax, currMax = 0, 0

        for i in range(start, end):
            temp = max(currMax, nums[i] + prevMax)
            prevMax = currMax
            currMax = temp

        return currMax
