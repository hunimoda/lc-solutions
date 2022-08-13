#include <vector>

using std::vector;

class Solution {
 public:
  bool ValidMountainArray(vector<int> &arr) {
    int size = arr.size(), pdx;

    if (size < 3) return false;

    for (pdx = 1; pdx < size - 2 && arr[pdx] < arr[pdx + 1]; pdx++)
      continue;
    for (int i = 0; i < pdx; i++)
      if (arr[i] >= arr[i + 1]) return false;
    for (int i = pdx; i < size - 1; i++)
      if (arr[i] <= arr[i + 1]) return false;
    
    return true;
  }
};