class Solution {
 public:
  int BitwiseComplement(int n) {
    if (n == 0) return 1;

    int mask = 1;
    while (n / mask) mask <<= 1;

    return ~n & --mask;
  }
};