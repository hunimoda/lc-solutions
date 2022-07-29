#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::sort;
using std::reverse;
using std::pow;

// class Solution {
//  public:
//   vector<int> SortedSquares(vector<int> &nums) {
//     for (auto &num : nums) num *= num;
//     sort(nums.begin(), nums.end());
//     return nums;
//   }
// };

class Solution {
 public:
  vector<int> SortedSquares(vector<int> &nums) {
    vector<int> result(nums.size());
    int i = 0, j = nums.size() - 1;

    for (int k = j; k >= 0; k--) {
      if (nums[i] + nums[j] > 0) {
        result[k] = pow(nums[j--], 2);
      } else {
        result[k] = pow(nums[i++], 2);
      }
    }

    return result;
  }
};