#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  int MinDeletionSize(const vector<string> &strs) {
    const int lines = strs.size();
    const int length = strs[0].length();
    int remove = 0;

    for (int i = 0, j = 1; i < length; i++, j = 1) {
      while (j < lines && strs[j - 1][i] <= strs[j][i]) j++;
      if (j != lines) remove++;
    }
    return remove;
  }
};