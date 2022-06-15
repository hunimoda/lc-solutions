#include <string>
#include <algorithm>
#include <cctype>

using std::string;
using std::swap;
using std::isalpha;

class Solution {
 public:
  string ReverseOnlyLetters(string &s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      while (i < j && !isalpha(s[i])) i++;
      while (i < j && !isalpha(s[j])) j--;
      swap(s[i++], s[j--]);
    }
    return s;
  }
};