#include <iostream>
#include <iomanip>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> ImageSmoother(vector<vector<int>> &image) {
    vector<vector<int>> result(image.size());
    for (int i = 0; i < image.size(); i++) {
      result[i].resize(image[i].size());
      for (int j = 0; j < image[i].size(); j++)
        result[i][j] = PixelSmoother(image, i, j);
    }
    return result;
  }

 private:
  int PixelSmoother(vector<vector<int>> &image, int i_target, int j_target) {
    int sum = 0, count = 0;
    for (int i = i_target - 1; i <= i_target + 1; i++) {
      for (int j = j_target - 1; j <= j_target + 1; j++) {
        if (0 <= i && i < image.size() && 0 <= j && j < image[0].size())
          sum += image[i][j], count++;
      }
    }
    return sum / count;
  }
};

void DisplayImage(vector<vector<int>> &image) {
  for (const auto &row : image) {
    for (const int pixel : row) {
      std::cout << std::setw(4) << pixel;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  vector<vector<int>> image = {
    { 100, 200, 100 }, 
    { 200,  50, 200 }, 
    { 100, 200, 100 }, 
  };
  DisplayImage(image);

  Solution solution;
  vector<vector<int>> result = solution.ImageSmoother(image);

  DisplayImage(result);
  return 0;
}