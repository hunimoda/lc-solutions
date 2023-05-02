#include <vector>

using std::vector;

class Solution {
 public:
  bool IsToeplitzMatrix(const vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
      //
    }
    for (int j = 1; j < n; j++) {
      //
    }
  }

 private:
  bool IsSameInDiagonal(const vector<vector<int>> &matrix,
                        int i, int j, int count) {
    bool same = true;
  }
};