#include <algorithm>

using std::max;

class Solution {
 public:
  int BinaryGap(int n) {
    int index = 0, prev_index = -1;
    int max_distance = 0;

    while (n) {
      if (n & 1) {
        if (prev_index != -1)
          max_distance = std::max(max_distance, index - prev_index);
        prev_index = index;
      }
      n >>= 1, index++;
    }

    return max_distance;
  }
};