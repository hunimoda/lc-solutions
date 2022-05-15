#include <iostream>
#include <cctype>
#include <string>
using std::string;

class Solution {
 public:
  bool IsPalindrome(string s) {
    size_t length{};
    for (size_t i{}; i < s.length(); i++) {
      if (std::isalpha(s[i]) || std::isdigit(s[i]))
        s[length++] = s[i] + (std::isupper(s[i]) ? 'a' - 'A' : 0);
    }
    for (size_t i{}; i < length / 2; i++) {
      if (s[i] != s[length - i - 1]) return false;
    }
    return true;
  }
};

int main() {
  string s;
  std::cout << "Input: ";
  std::getline(std::cin, s);
  
  Solution solution;
  std::cout << std::boolalpha << solution.IsPalindrome(s) << std::endl;
  return 0;
}