#include <vector>
using std::vector;

class Solution {
 public:
  int MaxProfit(vector<int> &prices) {
    int global_sum{0};
    int local_sum{0};
    for (size_t i{1}; i < prices.size(); i++) {
      local_sum = prices[i] - prices[i - 1] + std::max(local_sum, 0);
      if (local_sum > global_sum) global_sum = local_sum;
    }
    return global_sum;
  }
};