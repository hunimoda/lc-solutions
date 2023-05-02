#include <vector>
#include <algorithm>

using std::vector;
using std::min;

// SC: O(M + N)
class Solution {
 public:
  double FindMedianSortedArrays(const vector<int> &nums1,
                                const vector<int> &nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    vector<int> result;
    result.reserve(m + n);

    int i = 0, j = 0;
    while (i < m && j < n)
      result.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
    while (i < m) result.push_back(nums1[i++]);
    while (j < n) result.push_back(nums2[j++]);

    const int half = (m + n) / 2;
    if ((m + n) % 2) return result[half];
    return (static_cast<double>(result[half - 1]) + result[half]) / 2;
  }
};