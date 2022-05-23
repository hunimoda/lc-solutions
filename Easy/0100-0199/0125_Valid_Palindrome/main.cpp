#include <iostream>
#include <cctype>
#include <string>
using std::string;

class Solution {
 public:
  bool IsPalindrome(string s) {
    size_t left{0}, right{s.length() - 1};
    while (left < right) {
      if (!std::isalnum(s[left]))
        left++;
      else if (!std::isalnum(s[right]))
        right--;
      else if (std::tolower(s[left]) != std::tolower(s[right]))
        return false;
      else {
        left++;
        right--;
      }
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