#include <cmath>

class Solution {
 public:
  bool CheckPerfectNumber(int num) {
    int sum = 0, limit = static_cast<int>(std::sqrt(num));
    for (int div = 1; div <= limit; div++)
      if (num % div == 0) sum += div + num / div;
    return sum == 2 * num && num != 1;
  }
};