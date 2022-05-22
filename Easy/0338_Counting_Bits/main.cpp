#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> CountBits(int n) {
    vector<int> bit_counts{0};
    for (int i_limit = 1; i_limit <= n; i_limit <<= 1) {
      for (int i = 0; i <= std::min(i_limit - 1, n - i_limit); i++)
        bit_counts.push_back(1 + bit_counts[i]);
    }
    return bit_counts;
  }
};