#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> Transpose(vector<vector<int>> &matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> matrix_t(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        matrix_t[i][j] = matrix[j][i];
    }
    return matrix_t;
  }
};