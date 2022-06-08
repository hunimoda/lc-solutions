#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Solution {
 public:
  int DominantIndex(const vector<int> &nums) {
    pair<int, size_t> greatest = { nums[0], 0 };
    int greatest_2nd = -1, nums_size = nums.size();

    for (size_t i = 1; i < nums_size; i++) {
      if (nums[i] > greatest.first) {
        greatest_2nd = greatest.first;
        greatest = { nums[i], i };
      } else if (nums[i] > greatest_2nd) {
        greatest_2nd = nums[i];
      }
    }
    
    if (greatest.first >= 2 * greatest_2nd)
      return greatest.second;
    return -1;
  }
};