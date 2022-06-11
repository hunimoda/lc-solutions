#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

class Solution {
 public:
  vector<vector<int>> FlipAndInvertImage(vector<vector<int>> &image) {
    for (auto &row : image) {
      reverse(row.begin(), row.end());
      for (auto &pixel : row)
        pixel = pixel ? 0 : 1;
    }
    return image;
  }
};