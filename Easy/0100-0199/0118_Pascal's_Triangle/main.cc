#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> Generate(int n) {
    vector<vector<int>> result;
    result.reserve(n);

    for (int i = 1; i <= n; i++) {
      vector<int> row{1};
      row.reserve(i);

      for (int j = 0; j < i - 2; j++)
        row.push_back(result.back()[j] + result.back()[j + 1]);
      if (i > 1) row.push_back(1);
      result.push_back(row);
    }
    return result;
  }
};