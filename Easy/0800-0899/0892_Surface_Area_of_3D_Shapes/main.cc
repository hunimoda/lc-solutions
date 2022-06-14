#include <vector>

using std::vector;
using std::min;

//// My version of code
// class Solution {
//  public:
//   int SurfaceArea(const vector<vector<int>> &grid) {
//     int n = grid.size(), area = 0;
//     for (int i = 0; i < n; i++) {
//       for (int j = 0; j < n; j++) {
//         if (grid[i][j] == 0) continue;
//         area += 4 * grid[i][j] + 2;
//         if (i > 0)     area -= min(grid[i][j], grid[i - 1][j]);
//         if (i < n - 1) area -= min(grid[i][j], grid[i + 1][j]);
//         if (j > 0)     area -= min(grid[i][j], grid[i][j - 1]);
//         if (j < n - 1) area -= min(grid[i][j], grid[i][j + 1]);
//       }
//     }
//     return area;
//   }
// };

// Lee's version of code
class Solution {
 public:
  int SurfaceArea(const vector<vector<int>> &grid) {
    int n = grid.size(), area = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) area += 4 * grid[i][j] + 2;
        if (i) area -= 2 * min(grid[i][j], grid[i - 1][j]);
        if (j) area -= 2 * min(grid[i][j], grid[i][j - 1]);
      }
    }
    return area;
  }
};