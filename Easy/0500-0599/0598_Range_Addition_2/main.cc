#include <vector>

using std::vector;

class Solution {
 public:
  int MaxCount(int m, int n, vector<vector<int>> &ops) {
    int i_min = m, j_min = n;
    for (const auto &op : ops) {
      i_min = std::min(i_min, op.front());
      j_min = std::min(j_min, op.back());
    }
    return i_min * j_min;
  }
};