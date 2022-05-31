#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  int ArrayPairSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<>());
    int sum = 0, nums_size = nums.size();
    for (size_t i = 1; i < nums_size; i += 2)
      sum += nums[i];
    return sum;
  }
};