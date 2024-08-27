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

public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
  ListNode newHead;
  ListNode curr;

  if (list1 == null) {
    return list2;
  } else if (list2 == null) {
    return list1;
  } else if (list1.val < list2.val) {
    newHead = list1;
    list1 = list1.next;
  } else {
    newHead = list2;
    list2 = list2.next;
  }

  curr = newHead;

  while (list1 != null && list2 != null) {
    if (list1.val < list2.val) {
      curr.next = list1;
      list1 = list1.next;
    } else {
      curr.next = list2;
      list2 = list2.next;
    }
    curr = curr.next;
  }

  while (list1 != null) {
    curr.next = list1;
    list1 = list1.next;
    curr = curr.next;
  }
  while (list2 != null) {
    curr.next = list2;
    list2 = list2.next;
    curr = curr.next;
  }

  return newHead;
}