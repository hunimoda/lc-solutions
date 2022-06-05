#include <cstdint>

class Solution {
 public:
  bool HasAlternatingBits(uint32_t n) {
    uint32_t validator = n + (n >> 1);
    return (validator & validator + 1) == 0;
  }
};