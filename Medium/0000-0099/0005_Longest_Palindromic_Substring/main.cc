#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::max;
using std::vector;

// brute-force
class Solution {
 public:
  string LongestPalindrome(const string &s) {
    const int n = s.length();
    int max_i = 0, max_j = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (IsPalindrome(s, i, j) && j - i > max_j - max_i)
          max_i = i, max_j = j;
      }
    }
    return s.substr(max_i, max_j - max_i + 1);
  }

 private:
  bool IsPalindrome(const string &s, int i, int j) {
    while (i < j) if (s[i++] != s[j--]) return false;
    return true;
  }
};

// dynamic programming
class Solution {
 public:
  string LongestPalindrome(const string &s) {
    const int n = s.length();
    vector<vector<bool>> is_palindrome(n, vector<bool>(n + 1, true));
    int max_len = 1, max_i = 0;

    for (int len = 2; len <= n; len++) {
      for (int i = n - len; i >= 0; i--) {
        is_palindrome[i][len] =
            s[i] == s[i + len - 1] &&
            (len <= 3 || is_palindrome[i + 1][len - 2]);
        if (is_palindrome[i][len] && len > max_len)
          max_i = i, max_len = len;
      }
    }
    return s.substr(max_i, max_len);
  }
};