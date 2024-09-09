from typing import List


class Solution1:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # [0]: first, [1]: second, [2]: possible new first
        cache = [float('inf'), float('inf'), float('inf')]
        for num in nums:
            # sequence found: first < second < num
            if cache[1] < num:
                return True
            # found possible new first since num < cache[2] <= first
            elif num < cache[2]:
                cache[2] = num
            # found new smaller sequence start: cache[2] < num <= first
            elif cache[2] < num <= cache[0]:
                cache[0] = cache[2]
                cache[1] = num
            # found new second since first < num < second
            elif cache[0] < num < cache[1]:
                cache[1] = num
        return False


class Solution2:
    def increasingTriplet(self, nums: List[int]) -> bool:

        res = False

        if len(nums) < 3:
            return res

        first = second = float('inf')

        for i in range(0, len(nums)):
            if nums[i] <= first:
                first = nums[i]
            elif nums[i] <= second:
                second = nums[i]
            else:
                res = True

        return res
