class Solution {
 public:
  int ClimbStairs(int n) {
    if (n == 1 || n == 2) return n;
    int prev_1{2}, prev_2{1}, curr{};
    for (int i{3}; i <= n; i++) {
      curr = prev_1 + prev_2;
      prev_2 = prev_1;
      prev_1 = curr;
    }
    return curr;
  }
};