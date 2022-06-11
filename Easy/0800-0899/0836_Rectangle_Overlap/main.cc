#include <vector>

using std::vector;

class Solution {
 public:
  bool IsRectangleOverlap(const vector<int> &rec1, const vector<int> &rec2) {
    return IsAxisOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) ||
           IsAxisOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
  }

 private:
  bool IsAxisOverlap(int a1, int a2, int b1, int b2) {
    return a2 > b1 && b2 > a1;
  }
};