#include <string>

using std::string;

class Solution {
 public:
  bool RepeatedSubstringPattern(string s) {
    const size_t s_len = s.length();
    for (size_t p_len = 1; p_len <= s_len / 2; p_len++) {
      if (s[p_len] != s[0] || s_len % p_len) continue;
      bool matches = true;
      for (int i = 1; i <= s_len / p_len - 1 && matches; i++) {
        for (int j = 0; j < p_len && matches; j++)
          if (s[j] != s[p_len * i + j]) matches = false;
      }
      if (matches) return true;
    }
    return false;
  }
};