#include <queue>
#include <algorithm>

using std::queue;
using std::swap;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0, nullptr, nullptr) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

class Solution {
 public:
  bool IsSymmetric(TreeNode *root) {
    queue<TreeNode *> nodes({root->left, root->right});
    while (!nodes.empty()) {
      TreeNode *t1 = nodes.front(); nodes.pop();
      TreeNode *t2 = nodes.front(); nodes.pop();
      if (t1 == t2) continue;
      if (!t1 || !t2 || t1->val != t2->val) return false;

      nodes.push(t1->left), nodes.push(t2->right);
      nodes.push(t1->right), nodes.push(t2->left);
    }
    return true;
  }
};

class Solution {
 public:
  bool IsSymmetric(TreeNode *root) {
    return IsMirror(root->left, root->right);
  }

 private:
  bool IsMirror(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2 || t1->val != t2->val) return false;
    return IsMirror(t1->left, t2->right) && IsMirror(t1->right, t2->left);
  }
};

class Solution {
 public:
  bool IsSymmetric(TreeNode *root) {
    TreeNode *t1 = root->left;
    TreeNode *t2 = root->right;
    if (!t1 && !t2) return true;
    if (!t1 || !t2 || t1->val != t2->val) return false;

    swap(t1->left, t2->left);
    return IsSymmetric(t1) && IsSymmetric(t2);
  }
};