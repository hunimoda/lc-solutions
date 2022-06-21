#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::reverse;

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
  vector<int> PostorderTraversal(TreeNode *root) {
    vector<int> result;
    Helper(root, result);
    return result;
  }

 private:
  void Helper(TreeNode *root, vector<int> &result) {
    if (!root) return;
    Helper(root->left, result);
    Helper(root->right, result);
    result.push_back(root->val);
  }
};

// iterative - reverse of preorder
class Solution {
 public:
  vector<int> PostorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s({root});

    while (!s.empty()) {
      root = s.top(), s.pop();
      if (!root) continue;
      result.push_back(root->val);
      s.push(root->left), s.push(root->right);
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

// iterative - postorder
class Solution {
 public:
  vector<int> PostorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s({root});
    stack<TreeNode *>reverse;

    while (!s.empty()) {
      root = s.top(), s.pop();
      if (!root) continue;
      reverse.push(root);
      s.push(root->left), s.push(root->right);
    }
    while (!reverse.empty())
      result.push_back(reverse.top()->val), reverse.pop();

    return result;
  }
};