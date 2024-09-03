from collections import deque
from typing import List


class Solution1:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        queue = deque()
        queue.append(0)
        visited = set()
        visited.add(0)

        while queue:
            start = queue.popleft()
            if start == len(s):
                return True

            for word in wordDict:
                end = start + len(word)
                target = s[start:end]
                if target == word and end not in visited:
                    queue.append(end)
                    visited.add(end)
        return False


class Solution2:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        memo = [False] * (len(s) + 1)
        memo[len(s)] = True

        for i in range(len(s) - 1, -1, -1):
            for word in wordDict:
                if (i + len(word)) <= len(s) and s[i: len(word) + i] == word:
                    memo[i] = memo[i + len(word)]
                if memo[i]:
                    break
        return memo[0]
