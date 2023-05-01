#include <numeric>
#include <algorithm>
#include <vector>

using std::vector;
using std::max_element, std::min_element;
using std::accumulate;

class Solution {
 public:
  double average(vector<int> &salary) {
    int maxValue = *max_element(salary.begin(), salary.end());
    int minValue = *min_element(salary.begin(), salary.end());
    int sum = accumulate(salary.begin(), salary.end(), 0);
    return static_cast<double>(sum - maxValue - minValue) / (salary.size() - 2);
  }
};