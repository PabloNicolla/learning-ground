#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <math.h>

struct TrieNode
{
    std::unordered_map<char, TrieNode *> children{};
    bool isWord{false};
};

struct Trie
{
    TrieNode root{};

    void addWord(const std::string &word)
    {
        TrieNode *currNode = &root;

        for (const char c : word)
        {
            auto find = currNode->children.find(c);
            if (find != currNode->children.end())
            {
                currNode = find->second;
            }
            else
            {
                currNode->children[c] = new TrieNode;
                currNode = currNode->children[c];
            }
        }

        currNode->isWord = true;
    }
};

class Solution
{
    std::unordered_set<std::string> wordsFound{};
    std::unordered_set<char *> visited{}; // visited Cells... using memory address
    std::string builder{};

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
    {
        std::vector<std::string> answer{};
        Trie trie{};

        for (const std::string &word : words)
        {
            trie.addWord(word);
        }

        for (int row{}; row < board.size(); ++row)
        {
            for (int col{}; col < board[0].size(); ++col)
            {
                if (bfs(board, row, col, trie.root))
                {
                    trie.root.children.erase(board[row][col]);
                };
            }
        }

        for (const auto &word : wordsFound)
        {
            answer.emplace_back(word);
        }

        return answer;
    }

    bool bfs(std::vector<std::vector<char>> &board, const int row, const int col, const TrieNode &currTrieNode)
    {
        bool shouldDelete = false;

        if (row < 0 ||
            row >= board.size() ||
            col < 0 ||
            col >= board[0].size())
        {
            return false;
        }

        char *currChar = &board[row][col];
        const auto find = currTrieNode.children.find(*currChar);

        if (find == currTrieNode.children.end() || visited.find(currChar) != visited.end())
        {
            return false;
        }

        visited.insert(currChar);
        builder.push_back(*currChar);

        // if not empty do BFS
        // if BFS returns true, delete path

        if (!find->second->children.empty() && bfs(board, row - 1, col, *find->second))
        {
            find->second->children.erase(board[row - 1][col]);
        }
        if (!find->second->children.empty() && bfs(board, row + 1, col, *find->second))
        {
            find->second->children.erase(board[row + 1][col]);
        }
        if (!find->second->children.empty() && bfs(board, row, col - 1, *find->second))
        {
            find->second->children.erase(board[row][col - 1]);
        }
        if (!find->second->children.empty() && bfs(board, row, col + 1, *find->second))
        {
            find->second->children.erase(board[row][col + 1]);
        }

        if (find->second->isWord)
        {
            wordsFound.insert(builder);
            if (find->second->children.empty())
            {
                shouldDelete = true;
            }
        }

        if (!find->second->isWord && find->second->children.empty())
        {
            shouldDelete = true;
        }

        visited.erase(currChar);
        builder.pop_back();
        return shouldDelete;
    }
};

//  struct Cell {
//    int row{};
//    int col{};
//  };

// Define a custom hash function for Cell
//  struct CellHash {
//    std::size_t operator()(const Cell& cell) const {
//      // Simple hash combination of x and y using a common hashing technique
//      return std::hash<int>()(cell.x) ^ (std::hash<int>()(cell.y) << 1);
//    }
//  };

int main()
{

    Solution s{};
    std::vector<std::vector<char>> board{
        {'a', 'b', 'c', 'd'}, {'s', 'a', 'a', 't'}, {'a', 'c', 'k', 'e'}, {'a', 'c', 'd', 'n'}};
    std::vector<std::string> words{"bat", "cat", "back", "backend", "stack"};

    // std::vector<std::vector<char>> board{
    //   {'a','b'}
    // };
    // std::vector<std::string> words{ "ba"};
    s.findWords(board, words);
    return 0;
}