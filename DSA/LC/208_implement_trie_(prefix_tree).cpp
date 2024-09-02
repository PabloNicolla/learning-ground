#include <unordered_map>
#include <string>

struct TrieNode
{
    std::unordered_map<char, TrieNode *> trie{};
    bool isWord{false};
};

class PrefixTree
{
    TrieNode head{};

public:
    PrefixTree()
    {
    }

    void insert(std::string word)
    {
        TrieNode *curNode = &head;
        for (char c : word)
        {
            if (curNode->trie.find(c) != curNode->trie.end())
            {
                curNode = curNode->trie[c];
            }
            else
            {
                curNode->trie[c] = new TrieNode;
                curNode = curNode->trie[c];
            }
        }
        curNode->isWord = true;
    }

    bool search(std::string word)
    {
        TrieNode *curNode = &head;
        for (char c : word)
        {
            if (curNode->trie.find(c) != curNode->trie.end())
            {
                curNode = curNode->trie[c];
            }
            else
            {
                return false;
            }
        }
        return curNode->isWord;
    }

    bool startsWith(std::string prefix)
    {
        TrieNode *curNode = &head;
        for (char c : prefix)
        {
            if (curNode->trie.find(c) != curNode->trie.end())
            {
                curNode = curNode->trie[c];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

///////////////////////////////////////////////////// Solution 2
///////////////////////////////////////////////////// only a-z
class Trie
{
public:
    struct Node
    {
        bool flag = false;
        Node *link[26];
        bool containsKey(char c)
        {
            return (link[c - 'a'] != NULL);
        }
        void put(char c, Node *node)
        {
            link[c - 'a'] = node;
        }
        Node *get(char c)
        {
            return link[c - 'a'];
        }
    };
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(std::string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                Node *temp = new Node();
                node->put(word[i], temp);
            }
            node = node->get(word[i]);
        }
        node->flag = true;
    }

    bool search(std::string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->flag;
    }

    bool startsWith(std::string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
