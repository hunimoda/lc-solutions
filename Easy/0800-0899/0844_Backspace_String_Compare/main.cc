#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
 public:
  bool BackspaceCompare(string &s, string &t) {
    return ToTypedString(s) == ToTypedString(t);
  }

 private:
  string &ToTypedString(string &s) {
    int length = 0;
    for (auto c : s) {
      if (c != '#') {
        s[length++] = c;
      } else if (length > 0) {
        length--;
      }
    }
    s.resize(length);
    return s;
  }
};