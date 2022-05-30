#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> NextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> next_greater_element;
    for (const int &num : nums1)
      next_greater_element.push_back(GetNextGreaterElement(nums2, num));
    return next_greater_element;
  }

 private:
  int GetNextGreaterElement(const vector<int> &nums, const int target_num) {
    // Find target_num's index
    int target_idx;
    for (target_idx = 0; target_idx < nums.size(); target_idx++)
      if (nums[target_idx] == target_num) break;
    
    // Find next greater element
    for (size_t i = target_idx + 1; i < nums.size(); i++)
      if (nums[i] > target_num) return nums[i];
    return -1;
  }
};