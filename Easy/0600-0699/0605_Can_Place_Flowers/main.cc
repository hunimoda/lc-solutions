#include <vector>

using std::vector;

class Solution {
 public:
  bool CanPlaceFlowers(vector<int> &flowerbed, int n) {
    flowerbed.insert(flowerbed.end(), { 0, 1 });
    int empty_beds = 1;
    for (const int flower : flowerbed) {
      if (flower) {
        n -= (empty_beds - 1) / 2;
        if (n <= 0) return true;
        empty_beds = 0;
      } else {
        empty_beds++;
      }
    }
    flowerbed.resize(flowerbed.size() - 2);
    return false;
  }
};