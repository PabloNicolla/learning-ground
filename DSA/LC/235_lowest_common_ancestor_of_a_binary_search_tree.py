class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        cur = root

        while cur:
            if p.val < cur.val and q.val < cur.val:
                cur = cur.left
            elif p.val > cur.val and q.val > cur.val:
                cur = cur.right
            else:
                return cur

        return None


class Solution2:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def dfs(root: TreeNode):
            if root is None:
                return None

            if p.val == root.val or q.val == root.val:
                return root

            if p.val < root.val < q.val or p.val > root.val > q.val:
                return root

            if p.val < root.val:
                return dfs(root.left)

            if p.val > root.val:
                return dfs(root.right)

        return dfs(root)
