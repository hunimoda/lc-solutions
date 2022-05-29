#include <vector>

using std::vector;

class Solution {
 public:
  int FindMaxConsecutiveOnes(vector<int> &nums) {
    int ones = 0, max_ones = 0;
    for (const int &num : nums) {
      if (num == 0) ones = 0;
      else {
        ones++;
        max_ones = std::max(max_ones, ones);
      }
    }
    return max_ones;
  }
};