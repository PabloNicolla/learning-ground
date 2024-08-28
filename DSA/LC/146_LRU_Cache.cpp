#include <unordered_map>

class Node;

class LRUCache
{
    std::unordered_map<int, Node *> data{};
    Node head{0, 0};
    Node tail{0, 0};
    int cap{};

    void insert(Node *newNode)
    {
        Node *prev = tail.prev;
        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = &tail;
        tail.prev = newNode;
    }

    void remove(Node *toRemove)
    {
        Node *prev = toRemove->prev;
        Node *next = toRemove->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) : cap(capacity)
    {
        head.next = &tail;
        tail.prev = &head;
    }

    int get(int key)
    {
        const auto find = data.find(key);
        if (find != data.end())
        {
            Node *targetNode = find->second;
            remove(targetNode);
            insert(targetNode);
            return targetNode->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        const auto find = data.find(key);
        if (find == data.end())
        {
            if (data.size() < cap)
            {
                Node *newNode = new Node(key, value);
                data[key] = newNode;
                insert(newNode);
            }
            else
            {
                Node *oldest = head.next;
                data.erase(oldest->key);
                data[key] = oldest;
                oldest->key = key;
                oldest->val = value;
                remove(oldest);
                insert(oldest);
            }
        }
        else
        {
            Node *nodeFound = find->second;
            remove(nodeFound);
            insert(nodeFound);
            nodeFound->val = value;
        }
    }
};

class Node
{
public:
    int key{};
    int val{};
    Node *next{};
    Node *prev{};

    Node(const int key, const int val) : key(key), val(val) {};
};