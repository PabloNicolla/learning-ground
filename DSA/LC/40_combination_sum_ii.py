from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        combination = []

        def rec(index, total):
            if total > target or index >= len(candidates):
                if total == target:
                    res.append(combination.copy())
                return None

            combination.append(candidates[index])
            rec(index + 1, total + candidates[index])
            combination.pop()

            while index + 1 < len(candidates) and candidates[index] == candidates[index + 1]:
                index += 1

            rec(index + 1, total)

        rec(0, 0)
        return res
