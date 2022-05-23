class Solution {
 public:
  bool IsPowerOfFour(int n){
    // return __builtin_popcount(n) == 1 && !(__builtin_ctz(n) & 1);
    return n > 0 && !(n & (n - 1)) && !(n & 0xAAAAAAAA);
  }
};