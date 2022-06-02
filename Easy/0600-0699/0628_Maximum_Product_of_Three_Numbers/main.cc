#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  int MaximumProduct(vector<int> &nums) {
    if (nums.size() == 3) return nums[0] * nums[1] * nums[2];

    vector<int> pos, neg;
    for (const int num : nums)
      num >= 0 ? pos.push_back(num) : neg.push_back(num);
    std::sort(pos.begin(), pos.end(), std::greater<>());
    std::sort(neg.begin(), neg.end(), std::greater<>());

    if (pos.size() == 0) return neg[0] * neg[1] * neg[2];
    if (pos.size() < 3)
      return pos[0] * neg[neg.size() - 1] * neg[neg.size() - 2];
    if (neg.size() < 2) return pos[0] * pos[1] * pos[2];
    return pos[0] * std::max(pos[1] * pos[2],
                             neg[neg.size() - 1] * neg[neg.size() - 2]);
  }
};