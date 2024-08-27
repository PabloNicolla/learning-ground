#include <unordered_map>

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

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    // <Original Node Address -> Deep Copy Node Address>
    std::unordered_map<Node *, Node *> map{};
    Node *newHead = nullptr;
    Node *prev = nullptr;

    while (head != nullptr)
    {
      auto find = map.find(head);
      Node *newNode{};
      if (find == map.end())
      {
        newNode = new Node(head->val);
        map[head] = newNode;
        if (!newHead)
        {
          newHead = newNode;
        }
      }
      else
      {
        newNode = find->second;
      }

      if (prev)
      {
        prev->next = newNode;
      }

      if (head->random)
      {
        auto findRand = map.find(head->random);
        if (findRand != map.end())
        {
          newNode->random = findRand->second;
        }
        else
        {
          map[head->random] = new Node(head->random->val);
          newNode->random = map[head->random];
        }
      }

      prev = newNode;
      head = head->next;
    }

    return newHead;
  }
};
