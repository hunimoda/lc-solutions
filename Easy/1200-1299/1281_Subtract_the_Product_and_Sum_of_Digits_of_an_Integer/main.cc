class Solution {
 public:
  int SubtractProductAndSum(int n) {
    int product = 1, sum = 0;
    for (; n; n /= 10) product *= (n % 10), sum += (n % 10);
    return product - sum;
  }
};

int main() {
  Solution s;
  s.SubtractProductAndSum(705);
  return 0;
}