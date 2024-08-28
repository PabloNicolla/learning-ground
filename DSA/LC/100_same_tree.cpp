#include <functional>

struct TreeNode;

class Solution
{
public:
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    std::function<bool(TreeNode * p, TreeNode * q)> rec = [&](TreeNode *p, TreeNode *q) -> bool
    {
      if (p == nullptr || q == nullptr)
      {
        return p == q;
      }
      if (p->val != q->val)
      {
        return false;
      }
      bool same = rec(p->left, q->left);
      if (!same)
        return false;
      same = rec(p->right, q->right);
      return same;
    };

    return rec(p, q);
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