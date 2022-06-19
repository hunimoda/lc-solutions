#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <limits>

using std::min;
using std::stack;
using std::queue;
using std::pair;
using std::numeric_limits;

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
  int MinDepth(TreeNode *root) {
    if (!root) return 0;
    if (root->left && root->right)
      return min(MinDepth(root->left), MinDepth(root->right)) + 1;
    return MinDepth(root->left ? root->left : root->right) + 1;
  }
};

class Solution {
 public:
  int MinDepth(TreeNode *root) {
    if (!root) return 0;

    stack<pair<TreeNode *, int>> s;
    int depth = 0, min_depth = numeric_limits<int>::max();

    while (root || !s.empty()) {
      if (root) {
        s.push({root, ++depth});
        root = root->left;
      } else {
        root = s.top().first;
        depth = s.top().second;
        if (!(root->left) && !(root->right))
          min_depth = min(min_depth, depth);
        s.pop();
        root = root->right;
      }
    }
    return min_depth;
  }
};

class Solution {
 public:
  int MinDepth(TreeNode *root) {
    if (!root) return 0;

    queue<TreeNode *> q({nullptr, root});
    TreeNode *current;
    int depth = 0, size;

    while (!q.empty()) {
      current = q.front(), q.pop();
      if (current) {
        size = q.size();
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        if (q.size() == size) break;
      } else {
        depth++;
        q.push(current);
      }
    }
    return depth;
  }
};