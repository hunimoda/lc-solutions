#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> AddToArrayForm(vector<int> &num, int k) {
    int carry = 0, sum;
    int i = num.size() - 1;

    while (i >= 0 || k || carry) {
      sum = carry + k % 10;
      if (i >= 0) {
        sum += num[i];
        num[i--] = sum % 10;
      } else {
        num.insert(num.begin(), sum % 10);
      }
      carry = sum / 10;
      k /= 10;
    }
    return num;
  }
};