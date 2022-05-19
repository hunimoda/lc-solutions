#include <vector>

using std::vector;

class Solution {
 public:
  void MoveZeros(vector<int> &nums) {
    size_t left = 0, right = 0;
    while (right < nums.size()) {
      if (nums[right] != 0)
        nums[left++] = nums[right];
      right++;
    }
    while (left < nums.size())
      nums[left++] = 0;
  }
};