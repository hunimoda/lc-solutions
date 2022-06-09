#include <string>

using std::string;

class Solution {
 public:
  bool RotateString(const string &s, string &goal) {
    if (s.length() != goal.length()) return false;
    return (goal += goal).find(s) != string::npos;
  }
};