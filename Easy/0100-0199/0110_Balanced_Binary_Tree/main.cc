#include <algorithm>
#include <cmath>

using std::max;
using std::abs;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(0, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// recursive solution 1
class Solution {
 public:
  bool IsBalanced(TreeNode *root) {
    if (!root) return true;
    return IsBalanced(root->left) &&
           IsBalanced(root->right) &&
           abs(GetDepth(root->left) - GetDepth(root->right)) <= 1;
  }

 private:
  int GetDepth(TreeNode *root) {
    if (!root) return 0;
    return max(GetDepth(root->left), GetDepth(root->right)) + 1;
  }
};

// recursive solution 2
class Solution {
 public:
  bool IsBalanced(TreeNode *root) {
    return GetBalancedDepth(root) >= 0;
  }

 private:
  int GetBalancedDepth(TreeNode *root) {
    if (!root) return 0;
    int left_depth, right_depth;
    if ((left_depth = GetBalancedDepth(root->left)) < 0 ||
        (right_depth = GetBalancedDepth(root->right)) < 0 ||
        abs(left_depth - right_depth) > 1) {
      return -1;
    }
    return max(left_depth, right_depth) + 1;
  }
};