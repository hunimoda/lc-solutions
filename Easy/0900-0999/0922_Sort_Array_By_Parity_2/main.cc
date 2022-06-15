#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

//// By creating a new vector
// class Solution {
//  public:
//   vector<int> SortArrayByParityII(const vector<int> &nums) {
//     vector<int> sorted(nums.size());
//     int even = 0, odd = 1;

//     for (int num : nums) {
//       if (num & 1) {
//         sorted[odd] = num, odd += 2;
//       } else {
//         sorted[even] = num, even += 2;
//       }
//     }
//     return sorted;
//   }
// };

// Sorting in-place
class Solution {
 public:
  vector<int> SortArrayByParityII(vector<int> &nums) {
    int even = 0, odd = 1;
    const int n = nums.size();

    while (even < n && odd < n) {
      if (nums[even] % 2 == 0) {
        even += 2;
      } else if (nums[odd] % 2) {
        odd += 2;
      } else {
        swap(nums[even], nums[odd]);
      }
    }
    return nums;
  }
};

class Solution {
 public:
  vector<int> SortArrayByParityII(vector<int> &nums) {
    int even = 0, odd = 1;
    const int n = nums.size();

    while (true) {
      while (even < n && nums[even] % 2 == 0) even += 2;
      while (odd < n && nums[odd] % 2) odd += 2;
      if (even >= n || odd >= n) break;

      swap(nums[even], nums[odd]);
      even += 2, odd += 2;
    }
    return nums;
  }
};