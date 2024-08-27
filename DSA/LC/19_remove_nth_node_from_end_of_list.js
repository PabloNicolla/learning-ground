class ListNode {
    constructor(val, next) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}
function removeNthFromEnd(head, n) {
    let fast = head;
    let slow = head;
    let slowPrev = null;
    for (let i = 0; i < n; ++i) {
        fast = fast.next;
    }
    while (fast != null) {
        fast = fast.next;
        slowPrev = slow;
        slow = slow.next;
    }
    const next = slow.next;
    slow = null;
    if (slowPrev != null)
        slowPrev.next = next;
    else {
        head = next;
    }
    return head;
}
export {};
