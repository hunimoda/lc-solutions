#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  vector<int> NumberOfLines(const vector<int> &widths, const string &s) {
    int line_count = 1, width_sum = 0;
    for (const char c : s) {
      if (width_sum + widths[c - 'a'] > kMaxLineWidth)
        width_sum = 0, line_count++;
      width_sum += widths[c - 'a'];
    }
    return {line_count, width_sum};
  }

 private:
  const int kMaxLineWidth = 100;
};