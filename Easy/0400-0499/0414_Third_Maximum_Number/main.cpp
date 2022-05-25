#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  int ThirdMax(vector<int> &nums) {
    vector<int> max;
    for (const int &num : nums) {
      if (std::find(max.begin(), max.end(), num) != max.end()) continue;
      max.push_back(num);
      std::sort(max.begin(), max.end(), std::greater<int>());
      if (max.size() > 3) max.pop_back();
    }
    return max.size() == 3 ? max.back() : max.front();
  }
};