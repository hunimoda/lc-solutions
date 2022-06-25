#include <cmath>
#include <unordered_map>

using std::abs;
using std::unordered_map;

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
  int FindTilt(TreeNode *root) {
    if (!root) return 0;
    return abs(SumOfValues(root->left) - SumOfValues(root->right)) +
           FindTilt(root->left) + FindTilt(root->right);
  }

 private:
  int SumOfValues(TreeNode *root) {
    if (!root) return 0;
    return root->val + SumOfValues(root->left) + SumOfValues(root->right);
  }
};

class Solution {
 public:
  int FindTilt(TreeNode *root) {
    sum_table.clear(), sum_table.insert({nullptr, 0});
    PopulateSumTable(root);
    return FindTiltSum(root);
  }

  int FindTiltSum(TreeNode *root) {
    if (!root) return 0;
    return abs(sum_table[root->left] - sum_table[root->right]) +
           FindTiltSum(root->left) + FindTiltSum(root->right);
  }

  void PopulateSumTable(TreeNode *root) {
    if (!root) return;
    PopulateSumTable(root->left), PopulateSumTable(root->right);
    int root_sum = root->val + sum_table[root->left] + sum_table[root->right];
    sum_table.insert({root, root_sum});
  }

 private:
  unordered_map<TreeNode *, int> sum_table;
};

class Solution {
 public:
  int FindTilt(TreeNode *root) {
    int tilt_sum = 0;
    DepthFirst(root, tilt_sum);
    return tilt_sum;
  }

 private:
  int DepthFirst(TreeNode *root, int &tilt_sum) {
    if (!root) return 0;
    int left_sum = DepthFirst(root->left, tilt_sum);
    int right_sum = DepthFirst(root->right, tilt_sum);
    tilt_sum += abs(left_sum - right_sum);
    return root->val + left_sum + right_sum;
  }
};