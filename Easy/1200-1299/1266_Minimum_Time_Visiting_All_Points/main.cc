#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::abs;
using std::max;

class Solution {
 public:
  int MinTimeToVisitAllPoints(const vector<vector<int>> &points) {
    const int n = points.size();
    int result = 0;
    for (int i = 1; i < n; i++) {
      result += max(abs(points[i][0] - points[i - 1][0]),
                    abs(points[i][1] - points[i - 1][1]));
    }
    return result;
  }
};