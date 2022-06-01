#include <vector>
#include <set>

using std::vector;

class Solution {
 public:
  int DistributeCandies(vector<int> &candy_type) {
    std::set<int> candy_set(candy_type.begin(), candy_type.end());
    return std::min(candy_type.size() / 2, candy_set.size());
  }
};