#include <vector>

using std::vector;

class Solution {
 public:
  bool LemonadeChange(const vector<int> &bills) {
    int fives = 0, tens = 0;
    for (auto bill : bills) {
      if (bill == 5) fives++;
      else if (bill == 10) tens++, fives--;
      else if (tens) tens--, fives--;
      else fives -= 3;
      if (fives < 0) return false;
    }
    return true;
  }
};