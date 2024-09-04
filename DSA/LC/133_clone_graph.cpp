#include <vector>
#include <unordered_map>
#include <queue>

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        std::unordered_map<Node *, Node *> og_cp_map{};
        std::queue<Node *> toExplore{};

        toExplore.push(node);
        og_cp_map[node] = new Node(node->val);

        while (!toExplore.empty())
        {
            Node *curr = toExplore.front();
            toExplore.pop();

            for (Node *og_neighbour : curr->neighbors)
            {
                auto mapEntry = og_cp_map.find(og_neighbour);
                if (mapEntry == og_cp_map.end())
                {
                    og_cp_map[og_neighbour] = new Node(og_neighbour->val);
                    toExplore.push(og_neighbour);
                }
                og_cp_map[curr]->neighbors.push_back(og_cp_map[og_neighbour]);
            }
        }

        return og_cp_map[node];
    }
};