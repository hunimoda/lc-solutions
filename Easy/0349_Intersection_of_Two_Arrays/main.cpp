#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
 public:
  vector<int> Intersection(vector<int> &nums1, vector<int> &nums2) {
    // Create set from nums1 vector
    std::unordered_map<int, bool> nums1_map;
    for (const int &num : nums1)
      nums1_map.insert({num, false});

    // Loop through nums2 and add common numbers to return vector
    std::vector<int> common;
    for (const int &num : nums2) {
      if (nums1_map.count(num) && !nums1_map[num]) {
        common.push_back(num);
        nums1_map[num] = true;
      }
    }
    return common;
  }
};