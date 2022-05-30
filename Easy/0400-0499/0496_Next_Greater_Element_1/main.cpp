#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
 public:
  vector<int> NextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    std::unordered_map<int, int> map = { {nums2.back(), -1} };
    for (int i = nums2.size() - 2; i >= 0; i--) {
      int greater_num = nums2[i + 1];
      while (greater_num < nums2[i] && greater_num != -1)
        greater_num = map[greater_num];
      map[nums2[i]] = greater_num;
    }

    vector<int> next_greater_element;
    for (const int &num : nums1)
      next_greater_element.push_back(map[num]);
    return next_greater_element;
  }
};