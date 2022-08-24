#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <cmath>

using std::vector;
using std::array;
using std::queue;
using std::sort;
using std::abs;

// sort: O(NlogN), where N is row * col
class Solution {
 public:
  vector<vector<int>> AllCellsDistOrder(int rows, int cols,
                                        int r_center, int c_center) {
    const vector<int> origin{r_center, c_center};
    vector<vector<int>> result;
    result.reserve(rows * cols);

    for (int r = 0; r < rows; r++)
      for (int c = 0; c < cols; c++) result.push_back({r, c});
    sort(result.begin(), result.end(),
         [&](const auto &coord1, const auto &coord2) {
           return GetDistance(coord1, origin) < GetDistance(coord2, origin);
         });
    return result;
  }

 private:
  int GetDistance(const vector<int> &coord1, const vector<int> &coord2) {
    return abs(coord2[0] - coord1[0]) + abs(coord2[1] - coord1[1]);
  }
};

// O(N) solution, where N is row * col
class Solution {
 public:
  vector<vector<int>> AllCellsDistOrder(
      const int rows, const int cols, const int r_cen, const int c_cen) {
    const int n = rows * cols;
    vector<vector<int>> result{{r_cen, c_cen}};
    result.reserve(n);

    auto push_if_valid_coord =
        [&](int r, int c) {
          if (0 <= r && r < rows && 0 <= c && c < cols)
            result.push_back({r, c});
        };
    for (int r = r_cen - 1, c = c_cen; result.size() < n; r--) {
      for (; r < r_cen; r++, c--) push_if_valid_coord(r, c);
      for (; c < c_cen; r++, c++) push_if_valid_coord(r, c);
      for (; r > r_cen; r--, c++) push_if_valid_coord(r, c);
      for (; c > c_cen; r--, c--) push_if_valid_coord(r, c);
    }
    return result;
  }
};

// bfs
class Solution {
 public:
  vector<vector<int>> AllCellsDistOrder(int rows, int cols,
                                        int r_cen, int c_cen) {
    vector<vector<int>> result;
    queue<vector<int>> q;
    array<array<bool, 100>, 100> visited = {};

    result.reserve(rows * cols);
    q.push({r_cen, c_cen});
    visited[r_cen][c_cen] = true;

    while (!q.empty()) {
      vector<int> &curr = q.front();
      result.push_back({curr[0], curr[1]});

      for (auto &direction : directions_) {
        int row = curr[0] + direction[0];
        int col = curr[1] + direction[1];

        if (0 <= row && row < rows &&
            0 <= col && col < cols &&
            !visited[row][col]) {
          visited[row][col] = true;
          q.push({row, col});
        }
      }
      q.pop();
    }
    return result;
  }

 private:
  const int directions_[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};