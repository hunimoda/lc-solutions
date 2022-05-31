#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::string;

class Solution {
 public:
  string ReverseWords(string s) {
    std::stringstream ss(s);
    string word, reversed;
    while (ss >> word) {
      std::reverse(word.begin(), word.end());
      reversed += word + ' ';
    }
    reversed.pop_back();
    return reversed;
  }
};

int main() {
  Solution solution;
  std::cout << solution.ReverseWords("What a wonderful world!") << std::endl;
  return 0;
}