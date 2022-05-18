#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
 public:
  bool ContainsNearbyDuplicate(vector<int> &nums, int k) {
    std::unordered_map<int, int> record;
    for (size_t i = 0; i < nums.size(); i++) {
      if (record.count(nums[i])) {
        if (i - record[nums[i]] <= k) return true;
      }
      record[nums[i]] = i;
    }
    return false;
  }
};