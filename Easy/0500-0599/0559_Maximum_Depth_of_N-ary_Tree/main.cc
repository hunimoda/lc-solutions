#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

using std::vector;
using std::max;
using std::stack;
using std::queue;
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
  int MaxDepth(Node *root) {
    if (!root) return 0;
    int max_depth = 0;
    for (auto child : root->children)
      max_depth = max(max_depth, MaxDepth(child));
    return max_depth + 1;
  }
};

class Solution {
 public:
  int MaxDepth(Node *root) {
    int max_depth = 0, depth;
    stack<pair<Node *, int>> s;

    if (root) s.push({root, 1});
    while (!s.empty()) {
      root = s.top().first;
      depth = s.top().second;
      s.pop();

      if (root->children.empty())
        max_depth = max(max_depth, depth);
      for (auto child : root->children)
        s.push({child, depth + 1});
    }
    return max_depth;
  }
};

// bfs - what i first wrote
class Solution {
 public:
  int MaxDepth(Node *root) {
    int max_depth = 0, depth;
    queue<pair<Node *, int>> q;

    if (root) q.push({root, 1});
    while (!q.empty()) {
      root = q.front().first;
      depth = q.front().second;
      q.pop();

      if (!root->children.size()) {
        max_depth = max(max_depth, depth);
      } else {
        for (auto child : root->children) q.push({child, depth + 1});
      }
    }
    return max_depth;
  }
};

// bfs - better: no need to store pairs in queue
class Solution {
 public:
  int MaxDepth(Node *root) {
    int max_depth = 0, breadth;
    queue<Node *> q;

    if (root) q.push(root);
    while (!q.empty()) {
      breadth = q.size(), max_depth++;
      for (int i = 0; i < breadth; i++) {
        root = q.front(), q.pop();
        for (auto child : root->children) q.push(child);
      }
    }
    return max_depth;
  }
};