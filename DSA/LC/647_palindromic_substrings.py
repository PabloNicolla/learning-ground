class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0

        for i in range(len(s)):
            left, right = i, i
            while (left >= 0 and right < len(s) and s[left] == s[right]):
                count += 1
                left -= 1
                right += 1

            left, right = i, i + 1
            while (left >= 0 and right < len(s) and s[left] == s[right]):
                count += 1
                left -= 1
                right += 1

        return count
