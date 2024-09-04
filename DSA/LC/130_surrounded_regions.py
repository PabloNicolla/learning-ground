from typing import List

# /////////////////////////////////////////////////////////
# ///////////////////////////////////////////////////////// Using Set


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        ROW_SIZE, COL_SIZE = len(board), len(board[0])
        notSurrounded = set()

        def dfs(row: int, col: int) -> None:
            if (
                row < 0 or row >= ROW_SIZE or
                col < 0 or col >= COL_SIZE or
                board[row][col] == 'X' or (row, col) in notSurrounded
            ):
                return

            notSurrounded.add((row, col))
            dfs(row + 1, col)
            dfs(row - 1, col)
            dfs(row, col + 1)
            dfs(row, col - 1)

        for row in range(ROW_SIZE):
            if board[row][0] == 'O' and (row, 0) not in notSurrounded:
                dfs(row, 0)
            if board[row][COL_SIZE - 1] == 'O' and (row, COL_SIZE - 1) not in notSurrounded:
                dfs(row, COL_SIZE - 1)

        for col in range(COL_SIZE):
            if board[0][col] == 'O' and (0, col) not in notSurrounded:
                dfs(0, col)
            if board[ROW_SIZE - 1][col] == 'O' and (ROW_SIZE - 1, col) not in notSurrounded:
                dfs(ROW_SIZE - 1, col)

        for row in range(ROW_SIZE):
            for col in range(COL_SIZE):
                if board[row][col] == 'O' and (row, col) not in notSurrounded:
                    board[row][col] = 'X'


# /////////////////////////////////////////////////////////
# ///////////////////////////////////////////////////////// Not Using Set, replacing safe 'O' with 'T'


class Solution2:
    def solve(self, board: List[List[str]]) -> None:
        ROWS, COLS = len(board), len(board[0])

        def capture(r, c):
            if r < 0 or c < 0 or r == ROWS or c == COLS or board[r][c] != "O":
                return
            board[r][c] = "T"
            capture(r + 1, c)
            capture(r - 1, c)
            capture(r, c + 1)
            capture(r, c - 1)

        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "O" and (r in [0, ROWS - 1] or c in [0, COLS - 1]):
                    capture(r, c)

        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "O":
                    board[r][c] = "X"

        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "T":
                    board[r][c] = "O"
