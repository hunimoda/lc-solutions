#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> LuckyNumbers(const vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> result;

    for (int i = 0; i < m; i++) {
      int min_elem_j = 0;
      for (int j = 1; j < n; j++)
        if (matrix[i][j] < matrix[i][min_elem_j]) min_elem_j = j;

      int lucky = matrix[i][min_elem_j];
      for (int k = 0; k < m && lucky; k++)
        if (matrix[k][min_elem_j] > lucky) lucky = 0;

      if (lucky) result.push_back(lucky);
    }
    return result;
  }
};