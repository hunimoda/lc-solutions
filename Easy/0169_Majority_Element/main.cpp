#include <vector>

using std::vector;

class Solution {
 public:
  int MajorityElement(vector<int> &nums) {
    int cand{}, count{0};
    for (int num: nums) {
      if (count == 0) cand = num;
      count += (num == cand) ? 1 : -1;
    }
    return cand;
  }
};