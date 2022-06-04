#include <iostream>

using std::string;

class Solution {
 public:
  bool ValidPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j && s[i] == s[j]) i++, j--;
    return i >= j || IsPalindrome(s, i + 1, j) || IsPalindrome(s, i, j - 1);
  }

 private:
  bool IsPalindrome(string s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--)
      if (s[i] != s[j]) return false;
    return true;
  }
};