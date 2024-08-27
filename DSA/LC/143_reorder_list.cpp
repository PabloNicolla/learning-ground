struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  void reorderList(ListNode *head)
  {
    ListNode *fastPtr = head->next;
    ListNode *slowPtr = head;
    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
      fastPtr = fastPtr->next->next;
      slowPtr = slowPtr->next;
    }

    ListNode *first = head;
    ListNode *second = slowPtr->next;
    slowPtr->next = nullptr;

    ListNode *curr = second;
    ListNode *prev = nullptr;
    ListNode *next = second;

    while (next)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    ListNode *firstNext = first;
    ListNode *secondNext = second;
    second = prev;
    while (second)
    {
      firstNext = first->next;
      secondNext = second->next;
      first->next = second;
      second->next = firstNext;
      first = firstNext;
      second = secondNext;
    }
  }
};