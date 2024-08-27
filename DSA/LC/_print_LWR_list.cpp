#include <iostream>
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

void printLinkedList(Node *head)
{
  Node *curr = head;
  while (curr != nullptr)
  {
    std::cout << "[" << curr->val << ",";
    if (curr->random)
    {
      std::cout << curr->random->val;
    }
    else
    {
      std::cout << "null";
    }
    std::cout << "] -> ";
    curr = curr->next;
  }
  std::cout << "null" << std::endl;
}
