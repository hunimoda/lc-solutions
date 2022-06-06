#include <vector>

using std::vector;

class Solution {
 public:
  bool IsOneBitCharacter(vector<int> &bits) {
    if (bits.size() == 1 || *(bits.end() - 2) == 0) return true;
    int ones = 1;
    auto it = bits.crbegin() + 2;
    while (it != bits.crend() && *it == 1)
      it++, ones++;
    return ones % 2 == 0;
  }
};