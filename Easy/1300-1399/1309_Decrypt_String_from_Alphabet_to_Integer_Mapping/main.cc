#include <string>
#include <algorithm>

using std::string;
using std::stoi;
using std::reverse;

class Solution {
 public:
  string FreqAlphabets(const string &s) {
    string decrypt = "";
    int i = s.length() - 1, n;

    while (i >= 0) {
      if (s[i] == '#') {
        n = stoi(s.substr(i - 2, 2)), i -= 3;
      } else {
        n = s[i] - '1' + 1, i -= 1;
      }
      decrypt += 'a' + n - 1;
    }

    reverse(decrypt.begin(), decrypt.end());
    return decrypt;
  }
};