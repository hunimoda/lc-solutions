#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::sort;
using std::min;
using std::numeric_limits;

class Solution {
 public:
  vector<vector<int>> MinimumAbsDifference(const vector<int> &arr) {
    vector<int> copy = arr;
    sort(copy.begin(), copy.end());

    const int n = arr.size();
    int min_difference = numeric_limits<int>::max();
    vector<vector<int>> result;

    for (int i = 0; i < n - 1; i++)
      min_difference = min(min_difference, copy[i + 1] - copy[i]);
    for (int i = 0; i < n - 1; i++) {
      if (copy[i + 1] - copy[i] == min_difference)
        result.push_back({copy[i], copy[i + 1]});
    }

    return result;
  }
};