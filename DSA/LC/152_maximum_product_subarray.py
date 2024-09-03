from typing import List


class Solution1:
    def maxProduct(self, nums: List[int]) -> int:
        max_ans = nums[0]
        global_max = nums[0]
        global_min = nums[0]

        for i in range(1, len(nums)):
            local_max = nums[i]
            local_min = nums[i]

            local_min = min(local_min, nums[i] * global_max)
            local_min = min(local_min, nums[i] * global_min)

            local_max = max(local_max, nums[i] * global_max)
            local_max = max(local_max, nums[i] * global_min)

            global_max = local_max
            global_min = local_min

            max_ans = max(max_ans, global_max)

        return max_ans


class Solution2:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        curMin, curMax = 1, 1

        for n in nums:
            tmp = curMax * n
            curMax = max(n * curMax, n * curMin, n)
            curMin = min(tmp, n * curMin, n)
            res = max(res, curMax)
        return res


class Solution3:
    def maxProduct(self, nums: List[int]) -> int:
        dp = [nums[0]]
        max_prod = nums[0]

        for i in range(1, len(nums)):
            for j in range(0, len(dp)):
                dp[j] = nums[i] * dp[j]
                max_prod = max(max_prod, dp[j])
            dp.append(nums[i])
            max_prod = max(max_prod, nums[i])

        return max_prod


class Solution4:
    def maxProduct(self, nums: List[int]) -> int:
        dp = []
        max_prod = nums[0]
        start = 0

        dp.append(nums[0])

        for i in range(1, len(nums)):
            new_start = start
            dp_curr_len = len(dp)

            for j in range(start, dp_curr_len):
                new_prod = nums[i] * dp[j]
                dp.append(new_prod)

                if (new_prod > max_prod):
                    max_prod = new_prod
                new_start += 1

            start = new_start
            dp.append(nums[i])

            if nums[i] > max_prod:
                max_prod = nums[i]

        return max_prod
