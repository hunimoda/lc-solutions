#include <queue>

using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0, nullptr, nullptr) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// Recursive
class Solution {
 public:
  bool IsSameTree(TreeNode *p, TreeNode *q) {
    if (p == q) return true;
    if (!p || !q) return false;
    return p->val == q->val &&
           IsSameTree(p->left, q->left) &&
           IsSameTree(p->right, q->right);
  }
};

// Iterative
class Solution {
 public:
  bool IsSameTree(TreeNode *p, TreeNode *q) {
    queue<TreeNode *> nodes({p, q});

    while (!nodes.empty()) {
      p = nodes.front(), nodes.pop();
      q = nodes.front(), nodes.pop();
      if (!p && !q) continue;
      if (!p || !q || p->val != q->val) return false;

      nodes.push(p->left), nodes.push(q->left);
      nodes.push(p->right), nodes.push(q->right);
    }
    return true;
  }
};