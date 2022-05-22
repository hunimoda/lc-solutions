#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
 private:
  bool IsVowel(char c) {
    const char lower = std::tolower(c);
    return lower == 'a' || lower == 'e' || lower == 'i' ||
           lower == 'o' || lower == 'u';
  }

 public:
  string ReverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (!IsVowel(s[i])) i++;
      else if (!IsVowel(s[j])) j--;
      else std::swap(s[i++], s[j--]);
    }
    return s;
  }
};

int main() {
  string s = "Hello";
  Solution solution;
  std::cout << s << std::endl;
  std::cout << solution.ReverseVowels(s) << std::endl;
  std::cout << s << std::endl;
  return 0;
}