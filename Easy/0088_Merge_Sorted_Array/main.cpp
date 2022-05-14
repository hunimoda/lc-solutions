#include <vector>

using std::vector;

class Solution {
 public:
  void Merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> result{};
    int i{}, j{};
    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        result.push_back(nums1[i++]);
      } else {
        result.push_back(nums2[j++]);
      }
    }
    if (i < m)
      result.insert(result.end(), nums1.begin() + i, nums1.begin() + m);
    if (j < n)
      result.insert(result.end(), nums2.begin() + j, nums2.end());
    nums1 = std::move(result);
  }
};