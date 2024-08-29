#include <vector>
#include <unordered_set>
#include <functional>

struct TreeNode;

class Solution
{
public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        std::unordered_set<int> alreadyAdded{};
        TreeNode *root{};
        int pIndex{};
        int iIndex{};
        bool isSwapped{false};

        std::function<TreeNode *(TreeNode * &root)> rec = [&](TreeNode *&root) -> TreeNode *
        {
            if (pIndex == preorder.size())
                return nullptr;

            if (alreadyAdded.find(inorder[iIndex]) == alreadyAdded.end())
            {
                root = new TreeNode(preorder[pIndex]);
                alreadyAdded.insert(root->val);
                pIndex++;
                root->left = rec(root->left);
            }

            if (root != nullptr && inorder[iIndex] == root->val)
            {
                iIndex++;
                root->right = rec(root->right);
            }

            return root;
        };

        return rec(root);
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};