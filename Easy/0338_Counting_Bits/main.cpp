#include <vector>

using std::vector;

class Solution {
 private:
  int GetNumOfOnes(int n) {
    int count = 0;
    while (n) {
      if (n & 1) count++;
      n >>= 1;
    }
    return count;
  }
 public:
  vector<int> CountBits(int n) {
    vector<int> bits;
    for (int i = 0; i <= n; i++)
      bits.push_back(GetNumOfOnes(i));
    return bits;
  }
};