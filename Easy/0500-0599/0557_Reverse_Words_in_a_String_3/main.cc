#include <string>
#include <algorithm>

using std::string;

class Solution {
 public:
  string ReverseWords(string s) {
    for (size_t start = 0, end = 1; end <= s.size(); end++) {
      if (end != s.size() && s[end] != ' ') continue;
      std::reverse(s.begin() + start, s.begin() + end);
      start = end + 1, end = start;
    }
    return s;
  }
};