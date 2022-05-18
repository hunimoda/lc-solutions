#include <vector>

using std::vector;

class Solution {
 public:
  int MissingNumber(vector<int> &nums){
    int sum = 0;
    for (int num : nums)
      sum += num;
    const size_t n = nums.size();
    return n * (n + 1) / 2 - sum;
  }
};