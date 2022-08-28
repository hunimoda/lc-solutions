#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::sort;

class Solution {
 public:
  vector<vector<int>> ThreeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    const int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
      if (nums[i] > 0) break;

      const int target_sum = -nums[i];
      int j = i + 1, k = n - 1;

      while (j < k) {
        int current_sum = nums[j] + nums[k];
        if (current_sum != target_sum) {
          current_sum > target_sum ? k-- : j++;
          continue;
        }
        result.push_back({nums[i], nums[j], nums[k]});

        int prev_j = j, prev_k = k;
        while (j < k && nums[j] == nums[prev_j]) j++;
        while (j < k && nums[k] == nums[prev_k]) k--;
      }
      while (i < n - 2 && nums[i] == nums[i + 1]) i++;
    }
    return result;
  }
};

int main() {
  vector<int> test_case = {-1, 0, 1, 2, -1, -4, -3,
                           -3, -2, -2, -2, -1, 0, 1,
                           1, 2, 3, 3, 3, 4, 4, 5};
  Solution s;
  s.ThreeSum(test_case);
  return 0;
}