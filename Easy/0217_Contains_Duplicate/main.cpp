#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  bool ContainsDuplicate(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 1; i++)
      if (nums[i] == nums[i + 1]) return true;
    return false;
  }
};

int main() {
  Solution solution;
  vector<int> nums1{1};
  vector<int> nums2{1, 1};
  vector<int> nums3{2, 1};
  vector<int> nums4{1, 2, 1};
  vector<int> nums5{1, 2, 3, 1};
  vector<int> nums6{1, 2, 3, 4};
  vector<int> nums7{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  std::cout << std::boolalpha;
  std::cout << solution.ContainsDuplicate(nums1) << std::endl;
  std::cout << solution.ContainsDuplicate(nums2) << std::endl;
  std::cout << solution.ContainsDuplicate(nums3) << std::endl;
  std::cout << solution.ContainsDuplicate(nums4) << std::endl;
  std::cout << solution.ContainsDuplicate(nums5) << std::endl;
  std::cout << solution.ContainsDuplicate(nums6) << std::endl;
  std::cout << solution.ContainsDuplicate(nums7) << std::endl;
  return 0;
}