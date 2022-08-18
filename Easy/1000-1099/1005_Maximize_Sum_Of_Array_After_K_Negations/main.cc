#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
using std::min_element;
using std::sort;
using std::count_if;
using std::accumulate;

class Solution {
 public:
  int LargestSumAfterKNegations(const vector<int> &nums, int k) {
    vector<int> copy = nums;
    const int n = copy.size();

    sort(copy.begin(), copy.end());
    for (int i = 0; i < n && copy[i] < 0 && k; i++, k--) copy[i] *= -1;

    int sum = accumulate(copy.begin(), copy.end(), 0);
    if (k & 1) sum -= 2 * *min_element(copy.begin(), copy.end());
    return sum;
  }
};