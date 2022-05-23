int guess(int num);  // Pre-defined API

class Solution {
 public:
  int GuessNumber(int n) {
    int start = 1, end = n;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (!guess(mid)) return mid;
      else if (guess(mid) == 1) start = mid + 1;
      else end = mid - 1;
    }
    return start;
  }
};