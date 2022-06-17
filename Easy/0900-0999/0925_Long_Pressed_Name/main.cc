#include <string>

using std::string;

// My solution
class Solution {
 public:
  bool IsLongPressedName(const string &name, const string &typed) {
    if (name.length() > typed.length()) return false;

    auto it1 = name.begin();
    auto it2 = typed.begin();

    while (it1 != name.end()) {
      char c = *it1++;
      int count1 = 1, count2 = 0;

      while (it1 != name.end() && *it1 == c) it1++, count1++;
      while (it2 != typed.end() && *it2 == c) it2++, count2++;
      if (count1 > count2) return false;
    }
    return it2 == typed.end();
  }
};

// Lee's solution
class Solution {
 public:
  bool IsLongPressedName(const string &name, const string &typed) {
    int i = 0, n = name.length(), t = typed.length();
    for (int j = 0; j < t; j++) {
      if (i < n && name[i] == typed[j]) {
        i++;
      } else if (!j || typed[j] != typed[j - 1]) {
        return false;
      }
    }
    return i == n;
  }
};