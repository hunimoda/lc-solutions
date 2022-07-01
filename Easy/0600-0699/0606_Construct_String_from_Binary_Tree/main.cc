#include <string>

using std::string;
using std::to_string;

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
  string TreeToString(TreeNode *root) {
    string result;
    Helper(root, result);
    return result;
  }

 private:
  void Helper(TreeNode *root, string &s) {
    if (!root) return;
    s += to_string(root->val);
    if (root->left) s += "(", Helper(root->left, s), s += ")";
    if (root->right) {
      if (!(root->left)) s += "()";
      s += "(", Helper(root->right, s), s += ")";
    }
  }
};