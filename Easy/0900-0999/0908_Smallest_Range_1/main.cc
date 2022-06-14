#include <vector>
#include <algorithm>

using std::vector;
using std::minmax_element;
using std::max;

class Solution {
 public:
  int SmallestRangeI(vector<int> &nums, int k) {
    auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
    return max(*max_it - *min_it - 2 * k, 0);
  }
};