#include <functional>

struct TreeNode;

class Solution
{
public:
  int kthSmallest(TreeNode *root, int k)
  {
    int index{};

    std::function<TreeNode *(TreeNode * root)> rec = [&](TreeNode *root) -> TreeNode *
    {
      if (root == nullptr)
        return nullptr;

      TreeNode *output = rec(root->left);

      if (output != nullptr)
        return output;
      if (++index == k)
        return root;

      output = rec(root->right);

      if (output != nullptr)
        return output;

      return nullptr;
    };

    return rec(root)->val;
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