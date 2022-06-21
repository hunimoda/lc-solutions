#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right){}
};

class Solution {
 public:
  vector<int> PreorderTraversal(TreeNode *root) {
    vector<int> result;
    Helper(root, result);
    return result;
  }

 private:
  void Helper(TreeNode *root, vector<int> &result) {
    if (!root) return;
    result.push_back(root->val);
    Helper(root->left, result);
    Helper(root->right, result);
  }
};

class Solution {
 public:
  vector<int> PreorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s({root});

    while (!s.empty()) {
      root = s.top(), s.pop();
      if (!root) continue;
      result.push_back(root->val);
      s.push(root->right), s.push(root->left);
    }

    return result;
  }
};