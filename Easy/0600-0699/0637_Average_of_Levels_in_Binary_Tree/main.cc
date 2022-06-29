#include <vector>
#include <queue>

using std::vector;
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

class Solution {
 public:
  vector<double> AverageOfLevels(TreeNode *root) {
    vector<double> averages;
    queue<TreeNode *> q({root});
    while (!q.empty()) {
      double sum = 0;
      const size_t breadth = q.size();
      for (size_t i = 0; i < breadth; i++) {
        root = q.front(), q.pop();
        sum += root->val;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
      averages.push_back(sum / breadth);
    }
    return averages;
  }
};