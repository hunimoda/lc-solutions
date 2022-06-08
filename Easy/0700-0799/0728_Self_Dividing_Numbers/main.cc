class Solution {
 public:
  vector<int> SelfDividingNumbers(int left, int right) {
    vector<int> numbers;
    for (int n = left; n <= right; n++)
      if (IsSelfDividing(n)) numbers.push_back(n);
    return numbers;
  }

 private:
  bool IsSelfDividing(const int num) {
    for (int n = num; n; n /= 10) {
      int digit = n % 10;
      if (digit == 0 || num % digit)
        return false;
    }
    return true;
  }
};