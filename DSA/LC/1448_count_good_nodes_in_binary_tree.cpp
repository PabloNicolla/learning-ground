#include <functional>
#include <limits>

struct TreeNode;

class Solution
{
public:
  int goodNodes(TreeNode *root)
  {
    int count{};

    std::function<void(TreeNode * root, int maxSoFar)> rec = [&](TreeNode *root, int maxSoFar)
    {
      if (root == nullptr)
        return;

      if (maxSoFar < root->val)
      {
        ++count;
        maxSoFar = root->val;
      }

      rec(root->left, maxSoFar);
      rec(root->right, maxSoFar);
    };

    rec(root, std::numeric_limits<int>().min());

    return count;
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