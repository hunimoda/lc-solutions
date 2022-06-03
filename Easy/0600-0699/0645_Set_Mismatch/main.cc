#include <vector>
#include <cmath>

using std::vector;
using std::abs;

class Solution {
 public:
  vector<int> FindErrorNums(vector<int> &nums) {
    int sum = 0;
    for (const int num : nums)
      sum += abs(num), nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
    int n = nums.size(), missing_num = 0;
    for (int i = 0; !missing_num && i < n; i++)
      if (nums[i] > 0) missing_num = i + 1;
    return vector<int>{missing_num + sum - n * (n + 1) / 2, missing_num};
  }
};