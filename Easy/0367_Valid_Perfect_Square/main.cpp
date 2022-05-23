#include <cmath>

class Solution {
 public:
  bool IsPerfectSquare(int n) {
    int start = 1;
    int end = 46'340;

    while (start <= end) {
      int mid = (start + end) / 2;
      int power = std::pow(mid, 2);

      if (power > n) end = mid - 1;
      else if (power < n) start = mid + 1;
      else return true;
    }
    return false;
  }
};

// Using builtin function sqrt(x)
// #include <cmath>

// class Solution {
//  public:
//   bool IsPerfectSquare(int n) {
//     return std::pow(static_cast<int>(std::sqrt(n)), 2) == n;
//   }
// };