class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function removeNthFromStart(head: ListNode | null, n: number): ListNode | null {
  let curr: ListNode | null = head;
  let prev: ListNode | null = null;

  for (let i = 1; i < n; ++i) {
    prev = curr;
    curr = curr.next;
  }

  const next: ListNode | null = curr.next;
  curr = null;

  if (prev != null) prev.next = next;
  else {
    head = next;
  }

  return head;
}

// npm install -g ts-node
// ts-node filename.ts

// npm install -g typescript
// tsc yourfile.ts

// tsc --project tsconfig.json

export {};
