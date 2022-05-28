#include <iostream>
#include <cmath>

using std::pow;
using std::floor;
using std::log2;

class Solution {
 public:
  int FindComplement(int num) {
    return ~num ^ -static_cast<unsigned int>(pow(2, floor(log2(num)) + 1));
  }
};

int main() {
  Solution solution;
  std::cout << solution.FindComplement(2'147'483'647) << std::endl;
  return 0;
}