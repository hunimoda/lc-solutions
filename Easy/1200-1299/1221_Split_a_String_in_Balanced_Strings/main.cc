#include <string>

using std::string;

class Solution {
 public:
  int BalancedStringSplit(const string &s) {
    int bias = 0, result = 0;
    for (auto c : s) {
      bias += (c == 'R') ? 1 : -1;
      if (!bias) result++;
    }
    return result;
  }
};