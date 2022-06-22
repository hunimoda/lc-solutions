#include <string>
#include <algorithm>

using std::string;
using std::reverse;

class Solution {
 public:
  string ConvertToTitle(int column) {
    string title;
    while (column) {
      title += 'A' + (column - 1) % 26;
      column = (column - 1) / 26;
    }
    reverse(title.begin(), title.end());
    return title;
  }
};