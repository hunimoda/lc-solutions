#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
 public:
  string LicenseKeyFormatting(string s, int k) {
    int count = 0;
    string formatted;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '-') continue;
      if (count >= k) {
        formatted += '-';
        count = 0;
      }
      formatted += std::toupper(s[i]);
      count++;
    }
    std::reverse(formatted.begin(), formatted.end());
    return formatted;
  }
};

int main() {
  Solution solution;
  solution.LicenseKeyFormatting("5F3Z-2e-9-w", 4);
  solution.LicenseKeyFormatting("2-5g-3-J", 2);
  solution.LicenseKeyFormatting("-", 1);
  solution.LicenseKeyFormatting("abc345", 1);
  solution.LicenseKeyFormatting("abc345", 4);
  return 0;
}