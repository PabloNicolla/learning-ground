# n^3 Brute Force
class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_pal = ""
        combination = ""

        for i in range(len(s)):
            for j in range(len(s), i, -1):
                combination = s[i:j:]
                if self.isPalindrome(combination) and len(max_pal) < len(combination):
                    max_pal = combination

        return max_pal

    def isPalindrome(self, s: str) -> bool:
        start = 0
        end = len(s) - 1
        while start < end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
