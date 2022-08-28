#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::sort;
using std::abs;

class Solution {
 public:
  int ThreeSumClosest(vector<int> &nums, const int target) {
    sort(nums.begin(), nums.end());

    int closest = nums[0] + nums[1] + nums[2];
    const int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        const int current = nums[i] + nums[j] + nums[k];
        if (current == target) return target;
        if (abs(target - closest) > abs(target - current))
          closest = current;
        current > target ? k-- : j++;
      }
    }
    return closest;
  }
};