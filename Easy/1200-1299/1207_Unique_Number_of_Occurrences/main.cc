#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
 public:
  bool UniqueOccurrences(const vector<int> &arr) {
    unordered_map<int, int> freq;
    for (auto elem : arr) freq[elem]++;

    bool has_occurred[1001] = {};
    for (const auto &count : freq) {
      if (has_occurred[count.second]) return false;
      has_occurred[count.second] = true;
    }
    return true;
  }
};