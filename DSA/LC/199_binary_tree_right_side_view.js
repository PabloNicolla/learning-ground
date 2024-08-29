class TreeNode {
    constructor(val, left, right) {
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }
}
class CustomQueue {
    constructor() {
        this.items = [];
        this.length = 0;
    }
    enqueue(item) {
        this.items.push(item);
        this.length++;
    }
    dequeue() {
        this.length--;
        return this.items.shift();
    }
    front() {
        return this.items[0];
    }
    back() {
        return this.items[this.length - 1];
    }
}
function rightSideView(root) {
    let ans = [];
    let queue = new CustomQueue();
    if (root == null)
        return ans;
    queue.enqueue(root);
    while (queue.length > 0) {
        const levelSize = queue.length;
        let lastValidNode = queue.back();
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
export {};
