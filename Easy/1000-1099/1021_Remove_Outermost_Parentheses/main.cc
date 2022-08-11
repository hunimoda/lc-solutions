#include <string>

using std::string;

class Solution {
 public:
  string RemoveOuterParentheses(const string &s) {
    string result;
    int step = 0;

    for (char c : s) {
      step += (c == '(') ? 1 : -1;
      if (c == '(' && step != 1 || c == ')' && step != 0)
        result.push_back(c);
    }
    return result;
  }
};