#include <vector>
#include <string>
class TrieNode
{
public:
    std::vector<TrieNode *> children;
    bool word;

    TrieNode() : children(26, nullptr), word(false) {}
};

class WordDictionary
{
public:
    TrieNode *root;

    WordDictionary() : root(new TrieNode()) {}

    void addWord(std::string word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            if (cur->children[c - 'a'] == nullptr)
            {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->word = true;
    }

    bool search(std::string word)
    {
        return dfs(word, 0, root);
    }

private:
    bool dfs(std::string word, int j, TrieNode *root)
    {
        TrieNode *cur = root;

        for (int i = j; i < word.size(); i++)
        {
            char c = word[i];
            if (c == '.')
            {
                for (TrieNode *child : cur->children)
                {
                    if (child != nullptr && dfs(word, i + 1, child))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if (cur->children[c - 'a'] == nullptr)
                {
                    return false;
                }
                cur = cur->children[c - 'a'];
            }
        }
        return cur->word;
    }
};
