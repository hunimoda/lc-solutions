#include <string>

using std::string;

class Solution {
 public:
  int CountBinarySubstrings(const string &s) {
    int result = 0, count1 = 0, count2 = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i - 1]) {
        count2++;
      } else {
        result += std::min(count1, count2);
        count1 = count2, count2 = 1;
      }
    }
    result += std::min(count1, count2);
    return result;
  }
};