#include <limits>

using std::numeric_limits;

class Solution {
 public:
  int Reverse(int x) {
    int result = 0;
    for (; x; x /= 10) {
      if (result > kIntMax / 10 || result < kIntMin / 10)
        return 0;
      result = 10 * result + x % 10;
    }
    return result;
  }

 private:
  const int kIntMax = numeric_limits<int>::max();
  const int kIntMin = numeric_limits<int>::min();
};