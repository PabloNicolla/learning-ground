from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        combination = []

        def rec(index):
            if index >= len(s):
                ans.append(combination.copy())
                return

            for end in range(index + 1, len(s) + 1):
                if self.isPalindrome(index, end, s):
                    combination.append(s[index:end:])
                    rec(end)
                    combination.pop()

        rec(0)
        return ans

    def isPalindrome(self, start, end, string):
        end -= 1
        while start < end:
            if string[start] != string[end]:
                return False
            start += 1
            end -= 1
        return True
