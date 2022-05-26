#include <cmath>

class Solution {
 public:
  int ArrangeCoins(int n) {
    return std::floor(
        -0.5 + std::sqrt(0.25 + 2 * static_cast<unsigned int>(n)));
  }
};