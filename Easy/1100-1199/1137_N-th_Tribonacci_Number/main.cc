#include <array>

using std::array;

class Solution {
 public:
  int Tribonacci(int n) {
    array<int, 38> tribonacci = {0, 1, 1};
    for (int i = 3; i <= n; i++) {
      for (int j = i - 3; j < i; j++)
        tribonacci[i] += tribonacci[j];
    }
    return tribonacci[n];
  }
};