#include <vector>

using std::vector;

class Solution {
 public:
  vector<bool> PrefixesDivBy5(vector<int> &nums) {
    vector<bool> result(nums.size());
    for (int i = 0, x = 0; i < nums.size(); i++) {
      x = 2 * x + nums[i];
      result[i] = !(x %= 5);
    }
    return result;
  }
};