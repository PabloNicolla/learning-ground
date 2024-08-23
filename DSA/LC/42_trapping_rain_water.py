class Solution:
    def count_squares(self, start: int, layer: int, height: list[int]) -> int:
        count = 0
        for i in range(start, len(height)):
            if height[i] >= layer:
                return count
            count += 1
        return 0

    def trap(self, height: list[int]) -> int:
        total = 0
        for i, h in enumerate(height):
            for n in range(h):
                total += self.count_squares(i + 1, n + 1, height)
        return total
