#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
 public:
  bool backspaceCompare(const string &s, const string &t) {
    return ToStack(s) == ToStack(t);
  }

 private:
  stack<char> ToStack(const string &s) {
    stack<char> ss;
    for (auto c : s) {
      if (c != '#') {
        ss.push(c);
      } else if (!ss.empty()) {
        ss.pop();
      }
    }
    return ss;
  }
};