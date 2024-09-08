from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        stack = []

        def helper(closed_count, open_count):
            if closed_count == open_count == n:
                ans.append("".join(stack))
                return

            if open_count < n:
                stack.append("(")
                helper(closed_count, open_count + 1)
                stack.pop()

            if closed_count < open_count:
                stack.append(")")
                helper(closed_count + 1, open_count)
                stack.pop()

        helper(0, 0)
        return ans
