#include <stack>

using std::stack;

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
  bool IsSubtree(TreeNode *root, TreeNode *sub_root) {
    stack<TreeNode *> s_root({root});
    stack<TreeNode *> s_sub({sub_root});
    TreeNode *curr;

    while (!s_root.empty()) {
      root = s_root.top(), s_root.pop();
      int child = 0;
      if (root->left) s_root.push(root->left), child += 0b10;
      if (root->right) s_root.push(root->right), child += 0b01;

      curr = s_sub.top(), s_sub.pop();
      int child_sub = 0;
      if (curr->left) s_sub.push(curr->left), child_sub += 0b10;
      if (curr->right) s_sub.push(curr->right), child_sub += 0b01;

      if (root->val == curr->val && child == child_sub) {
        //
      }
    }
  }
};