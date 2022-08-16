#include <vector>
#include <algorithm>

using std::vector;
using std::count_if;

// // brute-force
// class Solution {
//  public:
//   int OddCells(int m, int n, const vector<vector<int>> &indices) {
//     vector<vector<int>> matrix(m, vector<int>(n, 0));
//     for (const auto &index : indices) {
//       for (int i = 0; i < m; i++) matrix[i][index[1]]++;
//       for (int j = 0; j < n; j++) matrix[index[0]][j]++;
//     }

//     int odds = 0;
//     for (const auto &row : matrix) {
//       for (auto cell : row)
//         if (cell & 1) odds++;
//     }
//     return odds;
//   }
// };

// improved version
class Solution {
 public:
  int OddCells(int m, int n, const vector<vector<int>> &indices) {
    vector<int> rows(m, 0);
    vector<int> cols(n, 0);

    for (const auto &idx : indices)
      rows[idx[0]]++, cols[idx[1]]++;
    
    auto predicate = [](int val) { return val & 1; };
    int odd_rows = count_if(rows.begin(), rows.end(), predicate);
    int odd_cols = count_if(cols.begin(), cols.end(), predicate);
    
    return n * odd_rows + m * odd_cols - 2 * odd_rows * odd_cols;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> indices = {{0, 1}, {1, 1}};
  solution.OddCells(2, 3, indices);
  return 0;
}