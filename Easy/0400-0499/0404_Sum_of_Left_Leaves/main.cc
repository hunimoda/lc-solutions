struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// recursive
class Solution {
 public:
  int SumOfLeftLeaves(TreeNode *root, bool is_left = false) {
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if (!left && !right)
      return is_left ? root->val : 0;

    int sum = 0;
    if (left) sum += SumOfLeftLeaves(left, true);
    if (right) sum += SumOfLeftLeaves(right, false);
    return sum;
  }
};