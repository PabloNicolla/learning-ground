class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        print(nums)
        for i in range(1, len(nums)):
            if nums[i-1] == nums[i]:
                return True
        return False