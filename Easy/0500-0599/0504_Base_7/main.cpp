#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
 public:
  string ConvertToBase7(int num) {
    string base_7;
    for (int n = std::abs(num); n != 0; n /= 7)
      base_7 += std::to_string(n % 7);
    std::reverse(base_7.begin(), base_7.end());
    return num > 0 ? base_7 : (num < 0 ? '-' + base_7 : "0");
  }
};

int main() {
  Solution solution;
  std::cout << solution.ConvertToBase7(-10000000) << std::endl;
  std::cout << solution.ConvertToBase7(100) << std::endl;
  std::cout << solution.ConvertToBase7(0) << std::endl;
  return 0;
}