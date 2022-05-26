#include <string>

using std::string;

class Solution {
 public:
  int CountSegments(string s) {
    int segments = 0;
    s += ' ';
    for (size_t i = 0; i < s.length() - 1; i++)
      if (s[i] != ' ' && s[i + 1] == ' ') segments++;
    return segments;
  }
};