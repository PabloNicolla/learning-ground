#include <vector>
#include <functional>
#include <string>
#include <sstream>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::string builder{};

        std::function<void(TreeNode *)> rec = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                builder.push_back(',');
                return;
            }

            for (char c : std::to_string(node->val))
            {
                builder.push_back(c);
            }
            builder.push_back(',');
            rec(node->left);
            rec(node->right);
        };
        rec(root);
        return builder;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        std::vector<std::pair<TreeNode *, int>> stack{};
        std::istringstream iss{data};
        std::string token{};

        std::getline(iss, token, ',');
        if (token == "")
            return nullptr;

        TreeNode *head = new TreeNode(std::stoi(token));
        stack.push_back({head, 0});

        while (std::getline(iss, token, ','))
        {
            if (token == "")
            {
                if (stack.back().second == 1)
                {
                    stack.pop_back();
                }
                else
                {
                    ++stack.back().second;
                }
                continue;
            }

            TreeNode *newNode = new TreeNode(std::stoi(token));
            if (stack.back().second == 0)
            {
                stack.back().first->left = newNode;
                ++stack.back().second;
                stack.push_back({newNode, 0});
            }
            else
            {
                stack.back().first->right = newNode;
                stack.pop_back();
                stack.push_back({newNode, 0});
            }
        }

        return head;
    }

    // // Decodes your encoded data to tree.
    // TreeNode *deserialize(std::string data)
    // {
    //     std::vector<std::pair<TreeNode *, int>> stack{};
    //     std::istringstream iss{data};
    //     std::string token{};

    //     std::getline(iss, token, ',');
    //     if (token == "")
    //         return nullptr;

    //     TreeNode *head = new TreeNode(std::stoi(token));
    //     stack.push_back({head, 0});

    //     while (std::getline(iss, token, ','))
    //     {
    //         if (token == "")
    //         {
    //             if (stack.back().second == 1)
    //             {
    //                 stack.pop_back();
    //             }
    //             else
    //             {
    //                 ++stack.back().second;
    //             }
    //             continue;
    //         }

    //         while (stack.back().second == 2)
    //         {
    //             stack.pop_back();
    //         }

    //         TreeNode *newNode = new TreeNode(std::stoi(token));
    //         if (stack.back().second == 0)
    //         {
    //             stack.back().first->left = newNode;
    //             ++stack.back().second;
    //             stack.push_back({newNode, 0});
    //         }
    //         else
    //         {
    //             stack.back().first->right = newNode;
    //             ++stack.back().second;
    //             stack.push_back({newNode, 0});
    //         }
    //     }

    //     return head;
    // }
};

int main()
{
    TreeNode t1{1};
    TreeNode t3{3};
    TreeNode t4{4};
    TreeNode t5{5};
    TreeNode t6{6};
    TreeNode t7{7};

    t1.right = &t3;
    t3.left = &t4;
    t4.left = &t5;
    t4.right = &t6;
    t3.right = &t7;

    Codec s = Codec();

    auto a1 = s.serialize(&t1);
    auto a2 = s.deserialize(a1);

    std::cout << a1 << "\n\n";
    return 0;
}