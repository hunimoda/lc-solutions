#include <string>

using std::string;

class Solution {
 public:
  string RemoveDuplicates(const string &s) {
    string result = "";
    for (char c : s) {
      if (result.length() > 0 && result.back() == c) {
        result.pop_back();
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};

class Solution {
 public:
  string RemoveDuplicates(string &s) {
    const int n = s.length();
    int len = 0;
    for (int i = 0; i < n; i++) {
      if (len && s[len - 1] == s[i]) {
        len--;
      } else {
        s[len++] = s[i];
      }
    }
    s.resize(len);
    return s;
  }
};