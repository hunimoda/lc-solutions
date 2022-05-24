#include <string>

using std::string;

class Solution {
 public:
  char FindTheDifference(string s, string t) {
    int counter[26] = { 0 };
    for (char c : t) counter[c - 'a']++;
    for (char c : s) counter[c - 'a']--;
    for (size_t i = 0; i < 26; i++)
      if (counter[i] == 1) return 'a' + i;
    return 0;
  }
};