from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = float('-inf')

        def rec(node: TreeNode) -> int:
            if node is None:
                return 0

            left_max_sum = rec(node.left)
            right_max_sum = rec(node.right)

            this_sum = node.val
            this_sum = max(this_sum, this_sum + left_max_sum)
            this_sum = max(this_sum, this_sum + right_max_sum)

            self.max_sum = max(self.max_sum, this_sum)

            return max(node.val + left_max_sum, node.val + right_max_sum, node.val)

        rec(root)
        return self.max_sum
