from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0

        def rec(root):
            if root is None:
                return 0

            left_max_depth = rec(root.left)
            right_max_depth = rec(root.right)
            # nonlocal diameter # Alternative method to avoid using self.
            self.diameter = max(self.diameter, left_max_depth + right_max_depth)
            return max(left_max_depth, right_max_depth) + 1

        rec(root)
        return self.diameter
