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
  TreeNode *SearchBST(TreeNode *root, int val) {
    while (root) {
      if (root->val == val) return root;
      root = (root->val > val) ? root->left : root->right;
    }
    return nullptr;
  }
};

class Solution {
 public:
  TreeNode *SearchBST(TreeNode *root, int val) {
    if (!root || root->val == val) return root;
    return SearchBST((root->val > val) ? root->left : root->right, val);
  }
};