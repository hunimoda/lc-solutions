#include <vector>
#include <numeric>

using std::vector;
using std::accumulate;

class Solution {
 public:
  bool CanThreePartsEqualSum(const vector<int> &arr) {
    const int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3) return false;

    const int target = sum / 3;
    int curr_sum = 0, count = 0;

    for (auto num : arr) {
      curr_sum += num;
      if (curr_sum == target) curr_sum = 0, count++;
    }
    return count >= 3;
  }
};