#include <string>

using std::string;

class Solution {
 public:
  bool JudgeCircle(string moves) {
    int x = 0, y = 0;
    for (const char c : moves) {
      switch (c) {
        case 'L': x--; break;
        case 'R': x++; break;
        case 'U': y++; break;
        case 'D': y--; break;
      }
    }
    return x == 0 && y == 0;
  }
};