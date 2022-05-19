#include <vector>

using std::vector;

class Solution {
 public:
  void MoveZeros(vector<int> &nums) {
    for (size_t l = 0, r = 0; r < nums.size(); r++)
      if (nums[r]) std::swap(nums[l++], nums[r]);
  }
};