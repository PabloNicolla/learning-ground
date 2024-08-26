import collections
import math
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = collections.defaultdict(set)
        cols = collections.defaultdict(set)
        squares = collections.defaultdict(set)

        for i in range(9):
            for j in range(9):
                cell = board[i][j]

                if cell == '.':
                    continue

                square_index = math.floor(i / 3) * 3 + math.floor(j / 3)

                if (
                        cell in rows[i]
                        or cell in cols[j]
                        or cell in squares[square_index]
                ):
                    return False

                rows[i].add(cell)
                cols[j].add(cell)
                squares[square_index].add(cell)
        return True
