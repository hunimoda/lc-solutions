#include <vector>

using std::vector;

class Solution {
 public:
  int PeakIndexInMountainArray(const vector<int> &arr) {
    int begin = 0, end = arr.size() - 1;
    while (begin < end) {
      int mid = (begin + end) / 2;
      arr[mid] > arr[mid + 1] ? end = mid : begin = mid + 1;
    }
    return begin;
  }
};