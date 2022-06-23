#include <string>
#include <vector>
#include <stack>
#include <utility>

using std::string;
using std::to_string;
using std::vector;
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

// recurisive
class Solution {
 public:
  vector<string> BinaryTreePaths(TreeNode *root) {
    vector<string> paths;
    FillUpPaths(root, "", paths);
    return paths;
  }

 private:
  void FillUpPaths(TreeNode *root, string path, vector<string> &paths) {
    path += to_string(root->val);
    if (!(root->left) && !(root->right)) {
      paths.push_back(path);
    } else {
      if (root->left) FillUpPaths(root->left, path + "->", paths);
      if (root->right) FillUpPaths(root->right, path + "->", paths);
    }
  }
};

// iterative
class Solution {
 public:
  vector<string> BinaryTreePaths(TreeNode *root) {
    vector<string> paths;
    stack<pair<TreeNode *, string>> s({{root, to_string(root->val)}});
    TreeNode *left, *right;

    while (!s.empty()) {
      auto [node, path] = s.top(); s.pop();
      left = node->left, right = node->right;

      if (!left && !right) paths.push_back(path);
      if (left) s.push({left, path + "->" + to_string(left->val)});
      if (right) s.push({right, path + "->" + to_string(right->val)});
    }
    return paths;
  }
};