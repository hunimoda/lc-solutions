#include <string>

using std::string;

class Solution {
 public:
  int FindLusLength(string a, string b) {
    if (a == b) return -1;
    return std::max(a.length(), b.length());
  }
};