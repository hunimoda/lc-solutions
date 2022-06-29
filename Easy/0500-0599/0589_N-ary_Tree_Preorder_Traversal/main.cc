#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct Node {
  int val;
  vector<Node *> children;
  Node() {}
  Node(int val) : val(val) {}
  Node(int val, vector<Node *> children) : val(val), children(children) {}
};

// recursive
class Solution {
 public:
  vector<int> Preorder(Node *root) {
    vector<int> result;
    Helper(root, result);
    return result;
  }

 private:
  void Helper(Node *root, vector<int> &result) {
    if (!root) return;
    result.push_back(root->val);
    for (auto child : root->children) Helper(child, result);
  }
};

// iterative
class Solution {
 public:
  vector<int> Preorder(Node *root) {
    vector<int> result;
    stack<Node *> s;
    if (root) s.push(root);
    while (!s.empty()) {
      root = s.top(), s.pop();
      result.push_back(root->val);
      auto it = root->children.rbegin();
      while (it != root->children.rend()) s.push(*it++);
    }
    return result;
  }
};