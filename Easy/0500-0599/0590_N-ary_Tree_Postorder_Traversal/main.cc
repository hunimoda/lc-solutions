#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using std::vector;
using std::stack;
using std::find;
using std::pair;

struct Node {
  int val;
  vector<Node *> children;
  Node() {}
  Node(int val) : val(val) {}
  Node(int val, vector<Node *> children) : val(val), children(children) {}
};

class Solution {
 public:
  vector<int> Postorder(Node *root) {
    vector<int> visited;
    Helper(root, visited);
    return visited;
  }

 private:
  void Helper(Node *root, vector<int> &visited) {
    if (!root) return;
    for (auto child : root->children) Helper(child, visited);
    visited.push_back(root->val);
  }
};

class Solution {
 public:
  vector<int> Postorder(Node *root) {
    if (!root) return {};

    vector<int> visited;
    stack<pair<Node *, Node *>> temp({{root, nullptr}});
    stack<Node *> branch;

    while (!temp.empty()) {
      if (branch.empty() || temp.top().second == branch.top()) {
        branch.push(temp.top().first), temp.pop();
        auto it = branch.top()->children.rbegin();
        while (it != branch.top()->children.rend())
          temp.push({*it++, branch.top()});
      } else {
        visited.push_back(branch.top()->val), branch.pop();
      }
    }
    while (!branch.empty())
      visited.push_back(branch.top()->val), branch.pop();

    return visited;
  }
};