#include <string>
#include <map>

using std::string;

class Solution {
 public:
  bool IsAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    std::map<char, int> counter;
    for (char c : s) {
      if (counter.count(c)) {
        counter[c]++;
      } else {
        counter[c] = 1;
      }
    }
    for (char c : t) {
      if (!counter.count(c) || counter[c] < 1) return false;
      counter[c]--;
    }
    return true;
  }
};