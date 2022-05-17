#include <iostream>
#include <cstring>
#include <string>

using std::string;

class Solution {
 public:
  bool IsIsomorphic(string s, string t) {
    char *const mapping = new char[128];
    char *const reverse_mapping = new char[128];
    std::memset(mapping, 0, 128);
    std::memset(reverse_mapping, 0, 128);
    for (size_t i = 0; i < s.length(); i++) {
      if (!mapping[s[i]] && !reverse_mapping[t[i]]) {
        mapping[s[i]] = t[i];
        reverse_mapping[t[i]] = s[i];
      } else if (!mapping[s[i]] || !reverse_mapping[t[i]]) {
        return false;
      } else if (mapping[s[i]] != t[i] || reverse_mapping[t[i]] != s[i]) {
        return false;
      }
    }
    delete[] mapping;
    delete[] reverse_mapping;
    return true;
  }
};

int main() {
  Solution solution;
  string s, t;

  std::cin >> s >> t;
  std::cout << std::boolalpha << solution.IsIsomorphic(s, t) << std::endl;
  return 0;
}