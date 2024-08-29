class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

class CustomQueue<T> {
  private items: T[] = [];
  length: number = 0;
  enqueue(item: T) {
    this.items.push(item);
    this.length++;
  }
  dequeue(): T | undefined {
    this.length--;
    return this.items.shift();
  }
  front(): T | undefined {
    return this.items[0];
  }
  back(): T | undefined {
    return this.items[this.length - 1];
  }
}

function rightSideView(root: TreeNode | null): number[] {
  let ans: number[] = [];
  let queue: CustomQueue<TreeNode> = new CustomQueue();

  if (root == null) return ans;

  queue.enqueue(root);

  while (queue.length > 0) {
    const levelSize = queue.length;
    let lastValidNode: TreeNode | null = queue.back();

    if (lastValidNode != null) {
      ans.push(lastValidNode.val);
    }

    for (let i = 0; i < levelSize; ++i) {
      const curNode = queue.dequeue();
      curNode.left && queue.enqueue(curNode.left);
      curNode.right && queue.enqueue(curNode.right);
    }
  }

  return ans;
}

// npm install -g ts-node
// ts-node filename.ts

// npm install -g typescript
// tsc yourfile.ts

// tsc --project tsconfig.json

export {};
