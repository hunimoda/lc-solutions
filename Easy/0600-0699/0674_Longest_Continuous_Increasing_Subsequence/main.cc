#include <vector>

using std::vector;

class Solution {
 public:
  int FindLengthOfLcis(vector<int> &nums) {
    int start = 0, max_length = 1;
    while (start < nums.size()) {
      int end = start + 1;
      while (end < nums.size() && nums[end] > nums[end - 1]) end++;
      max_length = std::max(max_length, end - start);
      start = end;
    }
    return max_length;
  }
};