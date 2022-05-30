class Solution {
 public:
  int Fibonacci(int n) {
    if (n <= 1) return n;
    int prev = 0, fibo = 1;
    for (int i = 2; i <= n; i++) {
      fibo += prev;
      prev = fibo - prev;
    }
    return fibo;
  }
};