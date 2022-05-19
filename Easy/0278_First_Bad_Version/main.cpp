bool IsBadVersion(int version);

class Solution {
 public:
  int FirstBadVersion(int n) {
    int start = 1, end = n;
    while (start < end) {
      int mid = start + (end - start) / 2;
      IsBadVersion(mid) ? end = mid : start = mid + 1;
    }
    return start;
  }
};