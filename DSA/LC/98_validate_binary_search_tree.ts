class TreeNode<T> {
  value: T;
  left: TreeNode<T> | null = null;
  right: TreeNode<T> | null = null;
  constructor(value: T) {
    this.value = value;
  }
}

function isValidBST(root: TreeNode<number> | null): boolean {
  let prev: number | null = null;

  function inorder(node: TreeNode<number> | null): boolean {
    if (node === null) return true;

    // In-order traversal: left -> node -> right
    if (!inorder(node.left)) return false;

    // Compare current node value with the previous one
    if (prev !== null && node.value <= prev) return false;
    prev = node.value;

    return inorder(node.right);
  }

  return inorder(root);
}

export {};
