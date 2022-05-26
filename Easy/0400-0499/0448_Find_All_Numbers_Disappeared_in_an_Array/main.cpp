#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  vector<int> FindDisappearedNumbers(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    nums.push_back(nums.size() + 1);

    vector<int> disappeared;
    int previous_num = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] == previous_num) continue;
      for (int n = previous_num + 1; n < nums[i]; n++)
        disappeared.push_back(n);
      previous_num = nums[i];
    }
    return disappeared;
  }
};