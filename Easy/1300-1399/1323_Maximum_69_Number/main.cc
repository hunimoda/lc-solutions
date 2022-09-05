class Solution {
 public:
  int Maximum69Number(int num) {
    int place = 1'000;
    while (place && (num / place % 10) != 6) place /= 10;
    return num + 3 * place;
  }
};