#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class Solution {
 public:
  vector<int> SortArrayByParity(vector<int> &nums) {
    const int n = nums.size();
    for (int slow = 0, fast = 0; fast < n; fast++)
      if (nums[fast] % 2 == 0) swap(nums[slow++], nums[fast]);
    return nums;
  }
};