#include <vector>

using std::vector;

class Solution {
 public:
  bool IsBoomerang(vector<vector<int>> &points) {
    if (points[0] == points[1] ||
        points[1] == points[2] ||
        points[2] == points[0]) {
      return false;
    }
    return (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]) !=
           (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]);
  }
};