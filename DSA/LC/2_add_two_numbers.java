class Solution {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummy = new ListNode();
    ListNode currNode = dummy;
    int carry = 0;

    while (carry != 0 || l1 != null || l2 != null) {
      int l1Value = 0;
      int l2Value = 0;
      if (l1 != null) {
        l1Value = l1.val;
        l1 = l1.next;
      }
      if (l2 != null) {
        l2Value = l2.val;
        l2 = l2.next;
      }
      int newValue = carry + l1Value + l2Value;
      carry = newValue / 10;
      newValue %= 10;
      currNode.next = new ListNode(newValue);
      currNode = currNode.next;
    }

    return dummy.next;
  }
}

class ListNode {
  int val;
  ListNode next;

  ListNode() {
  }

  ListNode(int val) {
    this.val = val;
  }

  ListNode(int val, ListNode next) {
    this.val = val;
    this.next = next;
  }
}