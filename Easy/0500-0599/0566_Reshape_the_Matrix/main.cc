#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> MatrixReshape(vector<vector<int>> &mat, int r, int c) {
    if (r * c != mat.size() * mat[0].size()) return mat;
    vector<int> linear;
    for (const auto &row : mat)
      linear.insert(linear.end(), row.begin(), row.end());
    vector<vector<int>> reshaped;
    for (int row = 0; row < r; row++) {
      const auto start = linear.begin() + row * c;
      const auto end = linear.begin() + (row + 1) * c;
      reshaped.push_back(vector<int>(start, end));
    }
    return reshaped;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> matrix = {
    {1, 2, 3, 4, 5, 6}, 
    {7, 8, 9, 0, 1, 2}
  };
  solution.MatrixReshape(matrix, 3, 4);
  return 0;
}