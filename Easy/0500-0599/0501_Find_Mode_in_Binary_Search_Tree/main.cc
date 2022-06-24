#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::max;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// generic binary tree (not specific to bst)
class Solution {
 public:
  vector<int> FindMode(TreeNode *root) {
    unordered_map<int, int> freq;
    vector<int> result;
    int max_count = 0;

    CountNodes(root, freq, max_count);
    for (const auto &[value, count] : freq)
      if (count == max_count) result.push_back(value);
    return result;
  }

 private:
  void CountNodes(TreeNode *root, unordered_map<int, int> &freq,
                  int &max_count) {
    if (!root) return;
    max_count = max(max_count, ++freq[root->val]);
    CountNodes(root->left, freq, max_count);
    CountNodes(root->right, freq, max_count);
  }
};

// morris inorder traversal
class Solution {
 public:
  vector<int> FindMode(TreeNode *root) {
    vector<int> result;
    int max_count = 0, count = 0, prev_val;

    TraverseInorder(
        root, [&](int val) {
          count = (!count || val == prev_val) ? count + 1 : 1;
          max_count = max(max_count, count);
          prev_val = val;
        });
    
    count = 0;
    TraverseInorder(
        root, [&](int val) {
          count = (!count || val == prev_val) ? count + 1 : 1;
          if (count == max_count) result.push_back(val);
          prev_val = val;
        });
    return result;
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