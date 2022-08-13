#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::sqrt;
using std::min;

class Solution {
 public:
  vector<int> DistributeCandies(int candies, int num_people) {
    vector<int> result(num_people, 0);
    for (int to_give = 1; candies; to_give++) {
      result[(to_give - 1) % num_people] += min(to_give, candies);
      candies -= min(to_give, candies);
    }
    return result;
  }
};