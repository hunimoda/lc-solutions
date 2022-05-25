#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  vector<string> FizzBuzz(int n) {
    vector<string> fizz_buzz;
    for (int i = 1; i <= n; i++) {
      string s;
      if (i % 3 == 0) s += "Fizz";
      if (i % 5 == 0) s += "Buzz";
      fizz_buzz.push_back(s.length() ? s : std::to_string(i));
    }
    return fizz_buzz;
  }
};