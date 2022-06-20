#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> GetRow(int row) {
    vector<int> result{1};
    result.reserve(row + 1);
    for (int i = 1; i <= row; i++)
      result.push_back(static_cast<long>(result[i - 1]) * (row - i + 1) / i);
    return result;
  }
};