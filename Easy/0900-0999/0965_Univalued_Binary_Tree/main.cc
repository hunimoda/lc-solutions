#include <stack>
#include <queue>

using std::stack;
using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// dfs recursive
class Solution {
 public:
  bool IsUnivaluedTree(TreeNode *root) {
    return GetUnivalueOf(root) >= 0;
  }

  int GetUnivalueOf(TreeNode *root) {
    if (root->left && (GetUnivalueOf(root->left) != root->val) ||
        root->right && (GetUnivalueOf(root->right) != root->val)) {
      return -1;
    }
    return root->val;
  }
};

// dfs iterative
class Solution {
 public:
  bool IsUnivaluedTree(TreeNode *root) {
    const int value = root->val;
    stack<TreeNode *> s({root});

    while (!s.empty()) {
      root = s.top(), s.pop();
      if (root->val != value) return false;
      if (root->left) s.push(root->left);
      if (root->right) s.push(root->right);
    }
    return true;
  }
};

// bfs
class Solution {
 public:
  bool IsUnivaluedTree(TreeNode *root) {
    const int value = root->val;
    queue<TreeNode *> q({root});

    while (!q.empty()) {
      const int width = q.size();
      for (int i = 0; i < width; i++) {
        root = q.front(), q.pop();
        if (root->val != value) return false;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }
    return true;
  }
};