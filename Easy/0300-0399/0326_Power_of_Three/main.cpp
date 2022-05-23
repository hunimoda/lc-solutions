class Solution {
 public:
  bool IsPowerOfThree(int n) {
    return n >= 1 && !(1'162'261'467 % n);
  }
};