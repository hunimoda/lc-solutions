#include <utility>

using std::pair;

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
  TreeNode *IncreasingBst(TreeNode *root) {
    return RecursiveHelper(root).first;
  }

 private:
  pair<TreeNode *, TreeNode *> RecursiveHelper(TreeNode *root) {
    if (!root) return {nullptr, nullptr};

    const auto left_range = RecursiveHelper(root->left);
    const auto right_range = RecursiveHelper(root->right);

    if (left_range.second) left_range.second->right = root;
    root->left = nullptr;
    root->right = right_range.first;

    return {left_range.first, right_range.second};
  }
};