#include <iostream>
#include <map>
#include <string>

using std::string;

class Solution {
 public:
  bool IsomorphicHelper(string s, string t) {
    std::map<char, char> map;
    for (size_t i = 0; i < s.size(); i++) {
      if (map.find(s[i]) != map.end()) {
        if (map[s[i]] != t[i]) return false;
      } else {
        map[s[i]] = t[i];
      }
    }
    return true;
  }
  bool IsIsomorphic(string s, string t) {
    return IsomorphicHelper(s, t) && IsomorphicHelper(t, s);
  }
};

int main() {
  Solution solution;
  string s, t;

  std::cin >> s >> t;
  std::cout << std::boolalpha << solution.IsIsomorphic(s, t) << std::endl;
  return 0;
}