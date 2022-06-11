#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

class Solution {
 public:
  vector<vector<int>> FlipAndInvertImage(vector<vector<int>> &image) {
    for (auto &row : image) {
      for (int i = 0, j = image.size() - 1; i <= j; i++, j--)
        if (row[i] == row[j]) row[i] = row[j] ^= 1;
    }
    return image;
  }
};