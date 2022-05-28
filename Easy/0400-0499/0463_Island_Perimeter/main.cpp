#include <vector>

using std::vector;

class Solution {
 public:
  int IslandPerimeter(vector<vector<int>> &grid) {
    int perimeter = 0;
    const int i_max = grid.size();
    const int j_max = grid[0].size();
    for (int i = 0; i < i_max; i++) {
      for (int j = 0; j < j_max; j++) {
        if (!grid[i][j]) continue;
        int more_lands = 0;
        if (i < i_max - 1 && grid[i + 1][j]) grid[i + 1][j]++, more_lands++;
        if (j < j_max - 1 && grid[i][j + 1]) grid[i][j + 1]++, more_lands++;
        perimeter += 5 - grid[i][j] - more_lands;
      }
    }
    return perimeter;
  }
};