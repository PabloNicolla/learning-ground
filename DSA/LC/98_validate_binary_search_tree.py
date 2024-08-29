from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def rec(root, min_v, max_v):
            if root is None:
                return True

            if root.val >= max_v or root.val <= min_v:
                return False

            return rec(root.left, min_v, root.val) and rec(root.right, root.val, max_v)

        return rec(root, float('-Inf'), float('Inf'))
