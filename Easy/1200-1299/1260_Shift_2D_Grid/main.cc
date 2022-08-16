#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> ShiftGrid(vector<vector<int>> &grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> shifted(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int new_idx = (n * i + j + k) % (m * n);
        shifted[new_idx / n][new_idx % n] = grid[i][j];
      }
    }
    return shifted;
  }
};