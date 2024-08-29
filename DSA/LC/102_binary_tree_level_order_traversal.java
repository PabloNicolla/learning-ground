import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Deque<TreeNode> bfsQueue = new LinkedList<>();
        ArrayList<List<Integer>> ans = new ArrayList<>();

        bfsQueue.add(root);

        while (!bfsQueue.isEmpty()) {
            int levelSize = bfsQueue.size();
            ArrayList<Integer> levelArray = new ArrayList<>();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode cur = bfsQueue.poll();
                if (cur != null) {
                    levelArray.add(cur.val);
                    bfsQueue.add(cur.left);
                    bfsQueue.add(cur.right);
                }
            }

            if (!levelArray.isEmpty()) {
                ans.add(levelArray);
            }
        }

        return ans;
    }
}