#include <string>

using std::string;

class Solution {
 public:
  int FirstUniqueCharacter(string s) {
    int count[26] = { 0 };
    for (const char &c : s)
      count[c - 'a']++;
    for (size_t i = 0; i < s.size(); i++)
      if (count[s[i] - 'a'] == 1) return i;
    return -1;
  }
};