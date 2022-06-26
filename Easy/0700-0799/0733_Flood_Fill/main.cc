#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> &FloodFill(vector<vector<int>> &image,
                                 int sr, int sc, int new_color) {
    if (image[sr][sc] != new_color)
      Helper(image, sr, sc, new_color, image[sr][sc]);
    return image;
  }

 private:
  void Helper(vector<vector<int>> &image, int sr, int sc,
              int new_color, int start_color) {
    if (sr < 0 || image.size() <= sr ||
        sc < 0 || image[0].size() <= sc ||
        image[sr][sc] != start_color) {
      return;
    }
    image[sr][sc] = new_color;
    Helper(image, sr - 1, sc, new_color, start_color);
    Helper(image, sr + 1, sc, new_color, start_color);
    Helper(image, sr, sc - 1, new_color, start_color);
    Helper(image, sr, sc + 1, new_color, start_color);
  }
};