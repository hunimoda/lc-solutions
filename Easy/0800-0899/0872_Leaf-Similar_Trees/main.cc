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
      : val(val), left(left), right(right) {}
};

class Solution {
 public:
  bool LeafSimilar(TreeNode *root1, TreeNode *root2) {
    return GetLeafSequence(root1) == GetLeafSequence(root2);
  }

 private:
  vector<int> GetLeafSequence(TreeNode *root) {
    vector<int> sequence;
    stack<TreeNode *> s({root});
    while (!s.empty()) {
      root = s.top(), s.pop();
      size_t size = s.size();
      if (root->right) s.push(root->right);
      if (root->left) s.push(root->left);
      if (s.size() == size) sequence.push_back(root->val);
    }
    return sequence;
  }
};