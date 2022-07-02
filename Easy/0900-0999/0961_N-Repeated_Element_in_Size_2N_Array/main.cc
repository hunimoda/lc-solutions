#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
 public:
  int RepeatedNTimes(vector<int> &nums) {
    bool seen[10'001] = {};
    int i = 0;
    while (!seen[nums[i]])
      seen[nums[i]] = true, i++;
    return nums[i];
  }
};

class Solution {
 public:
  int RepeatedNTimes(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int i = 1;
    while (nums[i - 1] < nums[i]) i++;
    return nums[i];
  }
};