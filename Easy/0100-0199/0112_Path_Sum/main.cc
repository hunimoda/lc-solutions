#include <stack>
#include <queue>
#include <utility>
#include <tuple>

using std::stack;
using std::queue;
using std::pair;
using std::tie;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// recursive dfs
class Solution {
 public:
  bool HasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    const int diff = sum - root->val;
    if (!(root->left) && !(root->right)) return diff == 0;
    return HasPathSum(root->left, diff) || HasPathSum(root->right, diff);
  }
};

// iterative dfs
class Solution {
 public:
  bool HasPathSum(TreeNode *root, int sum) {
    stack<pair<TreeNode *, int>> s;

    while (root || !s.empty()) {
      if (root) {
        s.push({root, sum -= root->val});
        root = root->left;
      } else {
        tie(root, sum) = s.top(), s.pop();
        if (!(root->left) && !(root->right) && !sum)
          return true;
        root = root->right;
      }
    }
    return false;
  }
};

// iterative bfs
class Solution {
 public:
  bool HasPathSum(TreeNode *root, const int sum) {
    if (!root) return false;

    queue<pair<TreeNode *, int>> q;
    q.push({root, root->val});

    while (!q.empty()) {
      auto [curr, acc] = q.front(); q.pop();
      if (acc == sum && !(curr->left) && !(curr->right)) return true;
      if (curr->left) q.push({curr->left, acc + curr->left->val});
      if (curr->right) q.push({curr->right, acc + curr->right->val});
    }
    return false;
  }
};