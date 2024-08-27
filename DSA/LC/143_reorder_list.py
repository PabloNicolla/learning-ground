from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head is None:
            return None

        def rec(target: ListNode, curr: ListNode) -> ListNode | None:
            if curr is None:
                return target

            target = rec(target, curr.next)

            if target is None:
                return None

            if target.next is curr or target is curr:
                curr.next = None
                return None

            next_target = target.next
            target.next = curr
            curr.next = next_target
            target = next_target

            return target

        rec(head, head.next)
