#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
 public:
  vector<int> Intersect(vector<int> &nums1, vector<int> &nums2) {
    std::unordered_map<int, int> counter;
    for (const int &num : nums1)
      counter.count(num) ? counter[num]++ : counter[num] = 1;

    vector<int> duplicate_common;
    for (const int &num : nums2) {
      if (counter.count(num) && counter[num] > 0) {
        counter[num]--;
        duplicate_common.push_back(num);
      }
    }
    return duplicate_common;
  }
};