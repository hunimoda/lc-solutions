#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool BuddyStrings(string &s, string &goal) {
    if (s.length() != goal.length()) return false;
    if (s == goal) return DuplicateCharExists(s);

    vector<int> different;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == goal[i]) continue;
      if (different.size() >= 2) return false;

      different.push_back(i);
    }

    if (different.size() == 1) return false;
    return s[different[0]] == goal[different[1]] &&
           s[different[1]] == goal[different[0]];
  }

 private:
  bool DuplicateCharExists(const string &s) {
    int counter[26] = {0};
    for (char c : s) {
      if (counter[c - 'a']) return true;
      counter[c - 'a']++;
    }
    return false;
  }
};