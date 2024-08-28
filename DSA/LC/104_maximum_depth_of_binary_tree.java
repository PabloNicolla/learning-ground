import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import javafx.util.Pair;

class Solution {
  public int maxDepth(TreeNode root) {
    if (root == null) {
      return 0;
    }
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
  }
}

// ITERATIVE DFS
class Solution2 {
  public int maxDepth(TreeNode root) {
    Stack<Pair<TreeNode, Integer>> stack = new Stack<>();
    stack.push(new Pair<>(root, 1));
    int res = 0;

    while (!stack.isEmpty()) {
      Pair<TreeNode, Integer> current = stack.pop();
      TreeNode node = current.getKey();
      int depth = current.getValue();

      if (node != null) {
        res = Math.max(res, depth);
        stack.push(new Pair<>(node.left, depth + 1));
        stack.push(new Pair<>(node.right, depth + 1));
      }
    }
    return res;
  }
}

// BFS
class Solution3 {
  public int maxDepth(TreeNode root) {
    Queue<TreeNode> q = new LinkedList<>();
    if (root != null) {
      q.add(root);
    }

    int level = 0;

    while (!q.isEmpty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        TreeNode node = q.poll();
        if (node.left != null) {
          q.add(node.left);
        }
        if (node.right != null) {
          q.add(node.right);
        }
      }
      level++;
    }
    return level;
  }
}

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