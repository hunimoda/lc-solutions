#include <vector>

using std::vector;

class Solution {
 public:
  int IslandPerimeter(vector<vector<int>> &grid) {
    int perimeter = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (!IsIsland(grid, i, j)) continue;
        if (!IsIsland(grid, i - 1, j)) perimeter++;
        if (!IsIsland(grid, i + 1, j)) perimeter++;
        if (!IsIsland(grid, i, j - 1)) perimeter++;
        if (!IsIsland(grid, i, j + 1)) perimeter++;
      }
    }
    return perimeter;
  }

 private:
  bool IsIsland(vector<vector<int>> &grid, int i, int j) {
    return (0 <= i && i < grid.size()) &&
           (0 <= j && j < grid[i].size()) &&
           (grid[i][j] == 1);
  }
};