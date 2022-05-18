#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
 public:
  bool ContainsNearbyDuplicate(vector<int> &nums, int k) {
    std::unordered_map<int, int> record;
    for (size_t i = 0; i < nums.size(); i++) {
      std::unordered_map<int, int>::const_iterator it = record.find(nums[i]);
      if (it != record.end()) {
        if (i - record[nums[i]] <= k) return true;
        record.erase(nums[i]);
      }
      record.insert({nums[i], i});  // 1
    }
    return false;
  }
};