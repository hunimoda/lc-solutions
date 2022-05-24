#include <string>

using std::string;

class Solution {
 public:
  char FindTheDifference(string s, string t) {
    char c = 0;
    for (char cs : s) c ^= cs;
    for (char ct : t) c ^= ct;
    return c;
  }
};