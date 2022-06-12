#include <vector>

using std::vector;

class Solution {
 public:
  int PeakIndexInMountainArray(const vector<int> &arr) {
    int peak = 0;
    while (arr[peak + 1] > arr[peak]) peak++;
    return peak;
  }
};