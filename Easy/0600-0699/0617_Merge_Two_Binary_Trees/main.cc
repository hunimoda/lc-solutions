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
  TreeNode *MergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) return nullptr;
    TreeNode *new_node =
        new TreeNode((root1 ? root1->val : 0) + (root2 ? root2->val : 0));
    new_node->left = MergeTrees(
        root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
    new_node->right = MergeTrees(
        root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
    return new_node;
  }
};