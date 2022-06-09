#include <algorithm>

using std::find;

class Solution {
 public:
  int CountPrimeSetBits(int left, int right) {
    int count = 0;
    int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    for (int n = left; n <= right; n++) {
      if (find(prime, prime + 8, __builtin_popcount(n)) != prime + 8)
        count++;
    }
    return count;
  }
};