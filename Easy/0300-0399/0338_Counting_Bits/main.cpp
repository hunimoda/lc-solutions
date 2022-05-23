#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> CountBits(int n) {
    vector<int> bit_counts{0};
    for (int i = 1; i <= n; i++)
      bit_counts.push_back(bit_counts[i >> 1] + (i & 1));
    return bit_counts;
  }
};