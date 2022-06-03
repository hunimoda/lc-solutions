#include <vector>

using std::vector;

class Solution {
 public:
  double FindMaxAverage(vector<int> &nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];
    int max_sum = sum;
    for (int start = 1, end = k; end < nums.size(); start++, end++) {
      sum += nums[end] - nums[start - 1];
      max_sum = std::max(max_sum, sum);
    }
    return static_cast<double>(max_sum) / k;
  }
};