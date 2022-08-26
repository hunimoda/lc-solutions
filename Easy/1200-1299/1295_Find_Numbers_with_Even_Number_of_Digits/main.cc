#include <vector>

using std::vector;

class Solution {
 public:
  int FindNumbers(const vector<int> &nums) {
    int count = 0;
    for (auto num : nums)
      if (NumOfDigits(num) % 2 == 0) count++;
    return count;
  }

 private:
  int NumOfDigits(int num) {
    int count = 0;
    for (; num; num /= 10) count++;
    return count;
  }
};