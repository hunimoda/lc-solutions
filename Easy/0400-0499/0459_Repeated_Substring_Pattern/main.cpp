#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool RepeatedSubstringPattern(string s) {
    const size_t s_len = s.length();
    for (size_t p_len = 1; p_len <= s_len / 2; p_len++) {
      if (s[p_len] != s[0] || s_len % p_len) continue;
      bool matches = true;
      for (int i = 1; i <= s_len / p_len - 1 && matches; i++) {
        for (int j = 0; j < p_len && matches; j++)
          if (s[j] != s[p_len * i + j]) matches = false;
      }
      if (matches) return true;
    }
    return false;
  }

  int FindSubstring(string haystack, string needle) {
    vector<int> lps(FillLpsArray(needle));
    size_t i = 0, j = 0;
    while (i < haystack.size() && j < needle.size()) {
      if (haystack[i] == needle[j]) i++, j++;
      else if (j == 0) i++;
      else j = lps[j - 1];
    }
    return j == needle.size() ? i - j : -1;
  }

 private:
  vector<int> FillLpsArray(string s) {
    vector<int> lps{0};
    size_t i = 1, len = 0;
    while (i < s.size()) {
      if (s[i] == s[len]) lps[i++] = ++len;
      else if (len == 0) lps[i++] = 0;
      else len = lps[len - 1];
    }
    return lps;
  }
};

void TestSubstring(string haystack, string needle) {
  Solution solution;
  const int index = solution.FindSubstring(haystack, needle);
  std::cout << "\n=========================================================="
            << std::endl;

  if (index == -1) {
    std::cout << "Pattern '" << needle << "' not found in:" << std::endl;
    std::cout << haystack << std::endl;
  } else {
    std::cout << "Pattern '" << needle << "' found!" << std::endl;
    std::cout << "----------------------------------------------------------" 
              << std::endl;
    std::cout << haystack << std::endl;
    for (int i = 0; i < index; i++) std::cout << ' ';
    std::cout << needle << std::endl;
  }

  std::cout << "=========================================================="
            << std::endl;
}

int main() {
  Solution solution;
  TestSubstring("Hello World", "llo");
  TestSubstring("abcdef", "def");
  TestSubstring("computer", "mpute8");
  TestSubstring("stringmatchingmat", "ingmat");
  TestSubstring("videobox", "videobox");
  TestSubstring("videobox", "vided");
  TestSubstring("videobox", "eob");
  return 0;
}