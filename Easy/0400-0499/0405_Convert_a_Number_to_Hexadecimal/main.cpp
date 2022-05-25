#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  string ToHex(int num) {
    string hex;
    do {
      hex = FourBitToHex(num & 0x0000'000f) + hex;
      num = (num >> 4) & 0x0fff'ffff;
    } while (num);
    return hex;
  }

 private:
  char FourBitToHex(int num) {
    if (0 <= num && num <= 9) return '0' + num;
    return num - 10 + 'a';
  }
};