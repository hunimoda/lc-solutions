#include <algorithm>
#include <stack>
#include <queue>

using std::swap;
using std::stack;
using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(0, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// depth-first, recursive
class Solution {
 public:
  TreeNode *InvertTree(TreeNode *root) {
    if (!root) return root;
    root->left = InvertTree(root->left);
    root->right = InvertTree(root->right);
    swap(root->left, root->right);  // swapping first is also ok
    return root;
  }
};

// depth-first (preorder), iterative
class Solution {
 public:
  TreeNode *InvertTree(TreeNode *root) {
    stack<TreeNode *> s({root});
    while (!s.empty()) {
      TreeNode *current = s.top(); s.pop();
      if (!current) continue;
      swap(current->left, current->right);
      s.push(current->left), s.push(current->right);
    }
    return root;
  }
};

// depth-first (inorder), iterative
class Solution {
 public:
  TreeNode *InvertTree(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *current = root;
    while (current || !s.empty()) {
      if (current) {
        s.push(current);
      } else {
        current = s.top(), s.pop();
        swap(current->left, current->right);
      }
      current = current->left;
    }
    return root;
  }
};

// breadth-first, iterative
class Solution {
 public:
  TreeNode *InvertTree(TreeNode *root) {
    queue<TreeNode *> q({root});
    TreeNode *current;

    while (!q.empty()) {
      current = q.front(), q.pop();
      if (!current) continue;
      swap(current->left, current->right);
      q.push(current->left), q.push(current->right);
    }
    return root;
  }
};