#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  bool CheckRecord(string s) {
    int absent = 0, late_in_row = 0;
    for (const char c : s) {
      if (c == 'L') {
        late_in_row++;
        if (late_in_row >= 3) return false;
      } else {
        late_in_row = 0;
        if (c == 'A' && ++absent >= 2) return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solution;
  solution.CheckRecord("PAL");
  return 0;
}