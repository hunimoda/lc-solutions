class Solution {
 public:
  bool DivisorGame(int n) {
    return !(n % 2);
  }
};

class Solution {
 public:
  bool DivisorGame(int n) {
    bool is_winner[1001]{false};
    for (int i = 2; i <= n; i++) {
      for (int div = 1; div <= i / 2 && !is_winner[i]; div++)
        is_winner[i] = (i % div == 0) && !is_winner[i - div];
    }
    return is_winner[n];
  }
};