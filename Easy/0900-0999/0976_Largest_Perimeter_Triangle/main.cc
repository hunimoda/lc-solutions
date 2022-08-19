#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
 public:
  int LargestPerimeter(const vector<int> &nums) {
    vector<int> copy = nums;
    sort(copy.begin(), copy.end());

    for (int i = copy.size() - 1; i >= 2; i--) {
      if (copy[i] < copy[i - 1] + copy[i - 2])
        return copy[i] + copy[i - 1] + copy[i - 2];
    }
    return 0;
  }
};