#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::min;

class Solution {
 public:
  bool IsAlienSorted(vector<string> &words, string &order) {
    int index[26];
    for (int i = 0; i < 26; i++)
      index[order[i] - 'a'] = i;

    for (int i = 1, j; i < words.size(); i++) {
      const int iter = min(words[i - 1].length(), words[i].length());
      for (j = 0; j < iter; j++) {
        char c1 = words[i - 1][j];
        char c2 = words[i][j];

        if (c1 == c2) continue;
        if (index[c1 - 'a'] < index[c2 - 'a']) break;
        return false;
      }
      if (j == iter && words[i - 1].length() > words[i].length())
        return false;
    }
    return true;
  }
};