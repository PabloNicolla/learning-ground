
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []

        phone_map = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"]
        }

        combination = []

        def rec(index):
            if index >= len(digits):
                if combination:
                    res.append("".join(combination))
                return

            for c in phone_map[digits[index]]:
                combination.append(c)
                rec(index + 1)
                combination.pop()

        rec(0)
        return res
