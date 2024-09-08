from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        start = 0
        end = len(matrix) - 1
        while (start <= end):
            mid = (end - start) // 2 + start
            if matrix[mid][0] <= target <= matrix[mid][-1]:
                return self.binS(matrix[mid], target)
            elif target < matrix[mid][0]:
                end = mid - 1
            else:
                start = mid + 1
        return False

    def binS(self, m_list: List[int], target: int) -> bool:
        start = 0
        end = len(m_list) - 1
        while (start <= end):
            mid = (end - start) // 2 + start
            if m_list[mid] == target:
                return True
            elif target < m_list[mid]:
                end = mid - 1
            else:
                start = mid + 1
        return False
