#include <vector>
#include <queue>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNode
{
  bool operator()(const ListNode *const t1, const ListNode *const t2)
  {
    return t1->val > t2->val;
  }
};

class Solution1
{
public:
  ListNode *mergeKLists(std::vector<ListNode *> lists)
  {
    std::priority_queue<ListNode *, std::vector<ListNode *>, CompareNode> pq{};

    for (ListNode *head : lists)
    {
      while (head)
      {
        pq.push(head);
        head = head->next;
      }
    }

    ListNode *dummy = new ListNode(0, nullptr);
    ListNode *curr = dummy;

    while (!pq.empty())
    {
      curr->next = pq.top();
      pq.pop();
      curr = curr->next;
    }

    curr->next = nullptr;

    ListNode *head = dummy->next;
    delete dummy;

    return head;
  }
};

class Solution2
{
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists)
  {
    std::priority_queue<ListNode *, std::vector<ListNode *>, CompareNode> pq;

    for (ListNode *head : lists)
    {
      if (head)
      {
        pq.push(head);
      }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    while (!pq.empty())
    {
      ListNode *top = pq.top();
      pq.pop();

      curr->next = top;
      curr = curr->next;

      if (top->next)
      {
        pq.push(top->next);
      }
    }

    ListNode *head = dummy->next;
    delete dummy;
    return head;
  }
};
