#include <vector>
#include <stack>
#include <unordered_set>

using std::vector;
using std::stack;
using std::unordered_set;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val = 0, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

/*// Recursive version
class Solution {
 public:
  vector<int> InorderTraversal(TreeNode *root) {
    if (!root) return {};

    vector<int> result{InorderTraversal(root->left)};
    vector<int> right{InorderTraversal(root->right)};

    result.push_back(root->val);
    result.insert(result.end(), right.begin(), right.end());
    return result;
  }
};*/

// Iterative version
class Solution {
 public:
  vector<int> InorderTraversal(TreeNode *root) {
    if (!root) return {};

    unordered_set<TreeNode *> visited{nullptr};
    stack<TreeNode *> s({root});
    vector<int> result;
    result.reserve(100);

    while (!s.empty()) {
      TreeNode *current = s.top();
      if (!visited.count(current->left)) {
        s.push(current->left);
      } else if (current->right && visited.count(current->right)) {
        s.pop();
      } else {
        result.push_back(current->val);
        visited.insert(current);

        if (!visited.count(current->right)) {
          s.push(current->right);
        } else {
          s.pop();
        }
      }
    }
    return result;
  }
};