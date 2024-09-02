from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited = set()

        def rec(row, col, index):
            if (
                row < 0
                or row >= len(board)
                or col < 0
                or col >= len(board[row])
            ):
                return False
            if (row, col) in visited:
                return False
            if board[row][col] != word[index]:
                return False
            if index + 1 == len(word):
                return True

            visited.add((row, col))

            result = (
                rec(row - 1, col, index + 1)
                or rec(row + 1, col, index + 1)
                or rec(row, col - 1, index + 1)
                or rec(row, col + 1, index + 1)
            )

            visited.remove((row, col))

            return result

        for row in range(len(board)):
            for col in range(len(board[row])):
                if rec(row, col, 0):
                    return True

        return False
