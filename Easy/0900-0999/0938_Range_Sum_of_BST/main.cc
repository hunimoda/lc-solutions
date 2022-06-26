struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

class Solution {
 public:
  int RangeSumBST(TreeNode *root, int low, int high) {
    if (!root) return 0;
    int sum = (low <= root->val && root->val <= high) ? root->val : 0;
    if (root->val > low) sum += RangeSumBST(root->left, low, high);
    if (root->val < high) sum += RangeSumBST(root->right, low, high);
    return sum;
  }
};