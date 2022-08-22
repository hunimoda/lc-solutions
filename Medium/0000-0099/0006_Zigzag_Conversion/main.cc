#include <string>

using std::string;

class Solution {
 public:
  string Convert(const string &s, int num_rows) {
    if (num_rows == 1) return s;

    const int n = s.length();
    int odd = 2 * (num_rows - 1), even = 0;
    string result = "";

    for (int row = 0; row < num_rows; row++) {
      bool is_odd = false;
      int idx = row;
      while (idx < n) {
        result += s[idx];
        idx += (!row || row == num_rows - 1) ?
                 odd + even : ((is_odd ^= true) ? odd : even);
      }
      odd -= 2, even += 2;
    }
    return result;
  }
};