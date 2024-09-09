from __future__ import annotations
from typing import Optional


class ListNode:
    def __init__(self, val=0, next: ListNode = None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        right = head
        left = dummy

        while right:
            for i in range(k):
                right = right.next
                if right is None and i != k - 1:
                    return dummy.next

            curr = left.next
            next = curr
            prev = right

            while next is not None and next is not right:
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next

            temp_next_left = left.next
            left.next = prev
            left = temp_next_left

        return dummy.next
