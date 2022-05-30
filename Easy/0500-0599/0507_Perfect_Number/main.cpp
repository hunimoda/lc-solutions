class Solution {
 public:
  bool CheckPerfectNumber(int num) {
    int sum = 0;
    for (int div = 1; div <= num / 2; div++)
      if (num % div == 0) sum += div;
    return sum == num;
  }
};