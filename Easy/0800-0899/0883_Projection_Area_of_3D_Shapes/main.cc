#include <algorithm>
#include <numeric>
#include <vector>

using std::max;
using std::accumulate;
using std::vector;

class Solution {
 public:
  int ProjectionArea(const vector<vector<int>> &grid) {
    int n = grid.size(), xy_count = 0;
    vector<int> max_x(n, 0), max_y(n, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) continue;

        max_x[i] = max(max_x[i], grid[i][j]);
        max_y[j] = max(max_y[j], grid[i][j]);
        xy_count++;
      }
    }

    return accumulate(max_x.begin(), max_x.end(), 0) + 
           accumulate(max_y.begin(), max_y.end(), 0) + xy_count;
  }
};