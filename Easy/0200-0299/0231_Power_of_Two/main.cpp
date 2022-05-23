#include <iostream>
#include <cmath>

class Solution {
 private:
  bool IsInteger(double x) {
    return x == std::floor(x);
  }

 public:
  bool IsPowerOfTwo(int n) {
    if (n < 1) return false;
    return IsInteger(std::log2(n));
  }
};