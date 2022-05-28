class Solution {
 public:
  int HammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
  }
};