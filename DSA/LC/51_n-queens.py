from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        solutions = []
        valid_chessboards = []
        queen_positions = []  # [(row, col)]
        forbidden_columns = set()

        def backtrack(row: int):
            if row == n:
                valid_chessboards.append(queen_positions.copy())
                return

            forbidden_diagonals = set()
            for row_index, col_index in queen_positions:
                row_diff = row - row_index
                forbidden_diagonals.add(col_index + row_diff)
                forbidden_diagonals.add(col_index - row_diff)

            for col in range(n):
                if col in forbidden_columns or col in forbidden_diagonals:
                    continue
                queen_positions.append((row, col))
                forbidden_columns.add(col)
                backtrack(row + 1)
                queen_positions.pop()
                forbidden_columns.remove(col)

        backtrack(0)

        for board in valid_chessboards:
            board_representation = [['.' for _ in range(n)] for _ in range(n)]
            for row, col in board:
                board_representation[row][col] = 'Q'
            solutions.append([''.join(row) for row in board_representation])

        return solutions
