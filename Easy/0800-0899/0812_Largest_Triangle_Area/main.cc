#include <vector>

using std::vector;

class Solution {
 public:
  double LargestTriangleArea(const vector<vector<int>> &points) {
    double max_area = 0.0;
    const int num_of_points = points.size();
    for (int i = 0; i < num_of_points - 2; i++) {
      for (int j = i + 1; j < num_of_points - 1; j++) {
        for (int k = j + 1; k < num_of_points; k++) {
          max_area = std::max(
              max_area,
              0.5 * std::abs(
                  points[i][0] * points[j][1] + points[j][0] * points[k][1] +
                  points[k][0] * points[i][1] - points[j][0] * points[i][1] -
                  points[k][0] * points[j][1] - points[i][0] * points[k][1]));
        }
      }
    }
    return max_area;
  }
};