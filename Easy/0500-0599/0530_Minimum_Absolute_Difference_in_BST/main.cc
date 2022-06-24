#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::numeric_limits;
using std::min;

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
  int GetMinimumDifference(TreeNode *root) {
    vector<int> sorted;
    InorderTraverse(root, sorted);
    int min_diff = numeric_limits<int>::max();
    for (int i = 1; i < sorted.size(); i++)
      min_diff = min(min_diff, sorted[i] - sorted[i - 1]);
    return min_diff;
  }

 private:
  void InorderTraverse(TreeNode *root, vector<int> &sorted) {
    if (!root) return;
    InorderTraverse(root->left, sorted);
    sorted.push_back(root->val);
    InorderTraverse(root->right, sorted);
  }
};

class Solution {
 public:
  int GetMinimumDifference(TreeNode *root) {
    int min_diff = numeric_limits<int>::max();
    int prev_val = -1;

    TraverseInorder(
        root, [&](int val) {
          if (prev_val >= 0)
            min_diff = min(min_diff, val - prev_val);
          prev_val = val;
        });
    return min_diff;
  }

 private:
  template <typename F>
  void TraverseInorder(TreeNode *root, F &&callback) {
    while (root) {
      TreeNode *pred = FindPredecessor(root);
      if (!pred || pred->right == root) {
        if (pred) pred->right = nullptr;
        callback(root->val);
        root = root->right;
      } else {
        pred->right = root;
        root = root->left;
      }
    }
  }

  TreeNode *FindPredecessor(TreeNode *curr) {
    if (!(curr->left)) return nullptr;
    TreeNode *pred = curr->left;
    while (pred->right != nullptr && pred->right != curr)
      pred = pred->right;
    return pred;
  }
};

class Solution {
 public:
  int GetMinimumDifference(TreeNode *root) {
    int min_diff = numeric_limits<int>::max(), prev_val = -1;
    InorderTraverse(root, prev_val, min_diff);
    return min_diff;
  }

 private:
  void InorderTraverse(TreeNode *root, int &prev_val, int &min_diff) {
    if (!root) return;
    InorderTraverse(root->left, prev_val, min_diff);
    if (prev_val >= 0)
      min_diff = min(min_diff, root->val - prev_val);
    prev_val = root->val;
    InorderTraverse(root->right, prev_val, min_diff);
  }
};