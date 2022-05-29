#include <vector>
#include <cmath>

using std::vector;

class Solution {
 public:
  vector<int> ConstructRectangle(int area) {
    for (int width = (int) std::sqrt(area); width > 1; width--)
      if (area % width == 0) return vector<int>{area / width, width};
    return vector<int>{area, 1};
  }
};