#include <vector>
#include <cmath>

using std::vector;
using std::abs;

class Solution {
 public:
  vector<int> FindDisappearedNumbers(vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); i++)
      nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    vector<int> disappeared;
    for (size_t i = 0; i < nums.size(); i++)
      if (nums[i] > 0) disappeared.push_back(i + 1);
    return disappeared;
  }
};