#include <vector>
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

Node *createLinkedList(std::vector<std::pair<int, int>> input)
{
  if (input.empty())
    return nullptr;

  std::vector<Node *> nodes;
  for (const auto &pair : input)
  {
    nodes.push_back(new Node(pair.first));
  }

  for (size_t i = 0; i < nodes.size(); ++i)
  {
    if (i < nodes.size() - 1)
    {
      nodes[i]->next = nodes[i + 1];
    }

    int random_index = input[i].second;
    if (random_index != -1)
    { // Use -1 to represent null
      nodes[i]->random = nodes[random_index];
    }
  }

  return nodes[0]; // Return the head of the linked list
}