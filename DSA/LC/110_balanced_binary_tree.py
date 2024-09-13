from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        def dfs(root: TreeNode) -> int:
            if root is None:
                return 0

            left_height = dfs(root.left)
            right_height = dfs(root.right)

            if left_height is None or right_height is None:
                return None

            if abs(left_height - right_height) > 1:
                return None

            return max(left_height, right_height) + 1

        return dfs(root) is not None
