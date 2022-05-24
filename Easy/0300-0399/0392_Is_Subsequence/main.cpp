#include <string>

using std::string;

class Solution {
 public:
  bool IsSubsequence(string s, string t) {
    size_t si = 0;
    for (size_t ti = 0; si < s.size() && ti < t.size(); ti++)
      if (s[si] == t[ti]) si++;
    return si == s.size();
  }
};