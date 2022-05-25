#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  int ThirdMax(vector<int> &nums) {
    vector<int> copy(nums);
    std::sort(copy.begin(), copy.end());
    int distinct = 1, last_number = copy[copy.size() - 1];
    for (int i = copy.size() - 2; i >= 0 && distinct < 3; i--) {
      if (copy[i] == last_number) continue;
      distinct++, last_number = copy[i];
    }
    return distinct == 3 ? last_number : copy[copy.size() - 1];
  }
};