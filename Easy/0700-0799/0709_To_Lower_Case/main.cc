#include <string>

using std::string;

class Solution {
 public:
  string ToLowerCase(string &s) {
    for (char &c : s)
      if (std::isupper(c)) c = std::tolower(c);
    return s;
  }
};