class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
  let fast: ListNode | null = head;
  let slow: ListNode | null = head;
  let slowPrev: ListNode | null = null;

  for (let i = 0; i < n; ++i) {
    fast = fast.next;
  }

  while (fast != null) {
    fast = fast.next;
    slowPrev = slow;
    slow = slow.next;
  }

  const next: ListNode | null = slow.next;
  slow = null;

  if (slowPrev != null) slowPrev.next = next;
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
