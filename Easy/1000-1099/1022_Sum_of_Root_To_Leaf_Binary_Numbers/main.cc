#include <stack>
#include <utility>

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
  int SumRootToLeaf(TreeNode *root) {
    int total_sum = 0;
    stack<pair<TreeNode *, int>> s;
    s.push({root, root->val});

    while (!s.empty()) {
      int path_num = s.top().second;
      root = s.top().first, s.pop();

      TreeNode *left = root->left, *right = root->right;
      for (TreeNode *child : {left, right})
        if (child) s.push({child, (path_num << 1) + child->val});
      if (!left && !right) total_sum += path_num;
    }

    return total_sum;
  }
};