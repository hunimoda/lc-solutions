#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val = 0, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

/*// Recursive
class Solution {
 public:
  vector<int> InorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root) InorderTraversalHelper(root, result);
    return result;
  }

 private:
  void InorderTraversalHelper(TreeNode *root, vector<int> &result) {
    if (root->left)
      InorderTraversalHelper(root->left, result);
    result.push_back(root->val);
    if (root->right)
      InorderTraversalHelper(root->right, result);
  }
};*/

// Iterative
class Solution {
 public:
  vector<int> InorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> next_visit;

    while (root || !next_visit.empty()) {
      if (root) {
        next_visit.push(root);
        root = root->left;
      } else {
        root = next_visit.top(), next_visit.pop();
        result.push_back(root->val);
        root = root->right;
      }
    }

    return result;
  }
};