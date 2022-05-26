#include <iostream>
#include <algorithm>
#include <string>

using std::string;

class Solution {
 public:
  string AddStrings(string num1, string num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    string sum;
    char carry = '0';
    for (size_t i = 0; i < std::max(num1.size(), num2.size()); i++) {
      char n1 = i < num1.size() ? num1[i] : '0';
      char n2 = i < num2.size() ? num2[i] : '0';
      sum += AddChar(n1, n2, carry);
    }
    if (carry == '1') sum += '1';

    std::reverse(sum.begin(), sum.end());
    return sum;
  }

 private:
  char AddChar(char a1, char a2, char &carry) {
    char sum = (a1 - '0') + (a2 - '0') + (carry - '0');
    carry = sum / 10 + '0';
    return sum % 10 + '0';
  }
};

int main() {
  Solution solution;
  std::cout << solution.AddStrings("11", "123") << std::endl;
  return 0;
}