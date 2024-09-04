
import collections
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        fresh = 0
        minutes = 0
        queue = collections.deque()

        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    fresh += 1
                if grid[row][col] == 2:
                    queue.append((row, col))

        while queue and fresh > 0:
            turn_size = len(queue)

            for _ in range(turn_size):
                cell = queue.popleft()

                for direction in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    row = cell[0] + direction[0]
                    col = cell[1] + direction[1]

                    if (row < 0 or row >= len(grid) or
                            col < 0 or col >= len(grid[0]) or
                            grid[row][col] != 1):
                        continue

                    grid[row][col] = 2
                    fresh -= 1
                    queue.append((row, col))
            minutes += 1
        return minutes if fresh == 0 else -1
