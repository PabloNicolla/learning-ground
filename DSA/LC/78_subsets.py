from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def rec(start, end, subSet):
            nonlocal res
            for i in range(start, end):
                tempSubSet = subSet.copy()
                tempSubSet.append(nums[i])
                rec(i + 1, end, tempSubSet)
            res.append(subSet)

        rec(0, len(nums), [])
        return res


class Solution2:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        subset = []

        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return
            subset.append(nums[i])
            dfs(i + 1)
            subset.pop()
            dfs(i + 1)

        dfs(0)
        return res
