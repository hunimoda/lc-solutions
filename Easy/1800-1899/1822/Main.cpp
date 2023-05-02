#include <vector>

using namespace std;

class Solution {
 public:
  int arraySign(vector<int> &nums) {
    int negativeNumbers = 0;
    for (int num : nums) {
      if (num < 0) {
        negativeNumbers++;  // Count only the negative numbers
      } else if (num == 0) {
        return 0;  // Any 0 would make the product 0
      }
    }
    // Odd number of negatives gives negative product
    return (negativeNumbers % 2) ? -1 : 1;
  }
};