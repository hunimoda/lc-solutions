#include <iostream>
#include <cmath>

using std::pow;

class Solution {
 public:
  bool IsHappy(int n) {
    bool seen[810] = {};
    while (n > 1) {
      int new_n = 0;
      for (; n; n /= 10) new_n += pow(n % 10, 2);
      if (seen[new_n]) return false;
      seen[n = new_n] = true;
    }
    return true;
  }
};

int main() {
  Solution s;
  std::cout << s.IsHappy(19) << std::endl;
  return 0;
}