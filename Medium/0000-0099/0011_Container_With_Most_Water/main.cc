#include <vector>
#include <algorithm>

using std::vector;
using std::max, std::min;

// improved brute-force
class Solution {
 public:
  int MaxArea(const vector<int> &height) {
    const int n = height.size();
    int max_area = 0;

    for (int i = 0, max_left = 0; i < n - 1; i++) {
      if (height[i] <= max_left) continue;
      max_left = height[i];

      for (int j = n - 1, max_right = 0; j > i && max_left > max_right; j--) {
        if (height[j] <= max_right) continue;
        max_right = height[j];

        max_area = max(max_area, min(max_left, max_right) * (j - i));
      }
    }
    return max_area;
  }
};

// two-pointers O(N) solution
class Solution {
 public:
  int MaxArea(const vector<int> &height) {
    int i = 0, j = height.size() - 1;
    int max_area = 0;
    while (i < j) {
      max_area = max(max_area, min(height[i], height[j]) * (j - i));
      height[i] < height[j] ? i++ : j--;
    }
    return max_area;
  }
};