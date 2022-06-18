#include <vector>

using std::vector;

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
  TreeNode *SortedArrayToBST(const vector<int> &nums) {
    return SortedArrayToBST(nums, 0, nums.size() - 1);
  }

  TreeNode *SortedArrayToBST(const vector<int> &nums, int front, int back) {
    if (front > back) return nullptr;
    int mid = front + (back - front) / 2;
    return new TreeNode(nums[mid],
                        SortedArrayToBST(nums, front, mid - 1),
                        SortedArrayToBST(nums, mid + 1, back));
  }
};