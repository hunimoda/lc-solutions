#include <iostream>
#include <cstdint>
#include <chrono>

using namespace std::chrono;

class Solution {
 public:
  uint32_t ReverseBits(uint32_t n) {
    uint32_t output = 0;
    for (int i = 0; i < 32; i++) {
      output <<= 1;
      output += n & 1;
      n >>= 1;
    }
    return output;
  }
};

int main() {
  Solution solution;
  std::cout << "# Starting timer..." << std::endl;
  auto start = high_resolution_clock::now();
  for (uint32_t i = 0; i <= 1'000'000'000; i++) {
    if (i % 10'000'000 == 0)
      std::cout << i / 10'000'000 << "%..." << std::endl;
    solution.ReverseBits(i);
  }
  std::cout << "# Timer END!" << std::endl;
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);
  std::cout << "# " << duration.count() << " [us] consumed" << std::endl;

  return 0;
}