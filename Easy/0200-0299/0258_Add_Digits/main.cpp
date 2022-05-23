class Solution {
 public:
  int AddDigits(int num) {
    if (num / 10 == 0) return num;
    int sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    return AddDigits(sum);
  }
};