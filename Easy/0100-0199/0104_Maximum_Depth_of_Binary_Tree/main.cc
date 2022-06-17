#include <algorithm>
#include <stack>
#include <utility>

using std::max;
using std::stack;
using std::pair;

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
  int MaxDepth(TreeNode *root) {
    return root ? max(MaxDepth(root->left), MaxDepth(root->right)) + 1 : 0;
  }
};

class Solution {
 public:
  int MaxDepth(TreeNode *root) {
    stack<pair<TreeNode *, int>> s;
    int current_depth = 0, max_depth = 0;

    while (root || !s.empty()) {
      if (root) {
        s.push({root, ++current_depth});
        root = root->left;
        max_depth = max(max_depth, current_depth);
      } else {
        auto &[node, depth] = s.top(); s.pop();
        root = node->right, current_depth = depth;
      }
    }
    return max_depth;
  }
};