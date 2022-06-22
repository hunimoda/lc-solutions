#include <deque>
#include <stack>
#include <algorithm>

using std::deque;
using std::stack;
using std::swap;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int val) : TreeNode(val, nullptr, nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

// for generic binary tree
class Solution {
 public:
  TreeNode *LowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    deque<TreeNode *> ancestors_of_p{GetAncestors(root, p)};
    deque<TreeNode *> ancestors_of_q{GetAncestors(root, q)};
    TreeNode *common_ancestor = nullptr;

    while (ancestors_of_p.front() == ancestors_of_q.front()) {
      common_ancestor = ancestors_of_p.front();
      ancestors_of_p.pop_front();
      ancestors_of_q.pop_front();
    }
    return common_ancestor;
  }

 private:
  deque<TreeNode *> GetAncestors(TreeNode *root, TreeNode *target) {
    deque<TreeNode *> deq;
    stack<TreeNode *> stk({root});

    while (stk.top() != target) {
      root = stk.top(), stk.pop();
      if (root->left) stk.push(root->left);
      if (root->right) stk.push(root->right);
      deq.push_back(root);

      while (!deq.empty() &&
             deq.back()->left != stk.top() &&
             deq.back()->right != stk.top())
        deq.pop_back();
    }
    deq.push_back(target);
    return deq;
  }
};

// recursive solution for bst
class Solution {
 public:
  TreeNode *LowestCommonAncestor(TreeNode *root,
                                 TreeNode *small, TreeNode *big) {
    if (small->val > big->val) swap(small, big);
    if (small == root ||
        big == root ||
        (small->val < root->val) && (root->val < big->val))
      return root;
    return LowestCommonAncestor(
        small->val > root->val ? root->right : root->left, small, big);
  }
};