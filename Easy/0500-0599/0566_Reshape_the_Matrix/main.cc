#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> MatrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c) return mat;
    vector<vector<int>> reshaped(r);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        reshaped[(n * i + j) / c].push_back(mat[i][j]);
    }
    return reshaped;
  }
};