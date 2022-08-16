#include <queue>

using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

class Solution {
 public:
  bool IsCousins(TreeNode *root, int x, int y) {
    queue<TreeNode *> q({root});
    TreeNode *parent_x = nullptr;
    TreeNode *parent_y = nullptr;

    while (!parent_x && !parent_y) {
      for (int i = q.size(); i >= 1; i--) {
        root = q.front(), q.pop();
        for (auto child : {root->left, root->right}) {
          if (!child) continue;
          q.push(child);
          if (child->val == x) parent_x = root;
          if (child->val == y) parent_y = root;
        }
      }
    }
    return parent_x && parent_y && (parent_x != parent_y);
  }
};