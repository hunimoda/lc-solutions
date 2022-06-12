#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

class Solution {
 public:
  bool BuddyStrings(string &s, string &goal) {
    if (s.length() != goal.length()) return false;
    if (s == goal)
      return unordered_set<char>(s.begin(), s.end()).size() < s.size();

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
};