#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
 public:
  int LhsLength(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (const int &num : nums) umap[num]++;
    int max_length = 0;
    for (const auto &[key, value] : umap) {
      if (umap.count(key + 1))
        max_length = std::max(max_length, value + umap[key + 1]);
    }
    return max_length;
  }
};

int main() {
  vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};
  Solution solution;
  solution.LhsLength(nums);
  return 0;
}