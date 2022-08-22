#include <string>
#include <limits>

using std::string;
using std::numeric_limits;

class Solution {
 public:
  int MyAtoi(const string &s) {
    const int n = s.length();
    int i = 0;

    // ignore any leading whitespace
    while (i < n && s[i] == ' ') i++;
    if (i >= n) return 0;

    // determine sign
    bool positive = true;
    if (s[i] == '+' || s[i] == '-')
      positive = (s[i++] == '+');

    // convert digits to integer
    int64_t result = 0;
    while (i < n && '0' <= s[i] && s[i] <= '9') {
      result = 10 * result + (positive ? 1 : -1) * (s[i++] - '0');
      if (result > kIntMax) return kIntMax;
      if (result < kIntMin) return kIntMin;
    }
    return result;
  }

 private:
  const int kIntMin = numeric_limits<int>::min();
  const int kIntMax = numeric_limits<int>::max();
};