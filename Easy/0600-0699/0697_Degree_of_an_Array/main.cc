#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::max;
using std::min;

class Solution {
 public:
  int FindShortestSubArray(const vector<int> &nums) {
    int max_count = 1, nums_size = nums.size();
    unordered_map<int, Record> umap;
    for (int i = 0; i < nums_size; i++) {
      if (umap.count(nums[i])) {
        max_count = max(max_count, ++umap[nums[i]].count);
        umap[nums[i]].range.second = i;
      } else {
        umap[nums[i]] = { 1, { i, i } };
      }
    }
    int min_range = nums_size;
    for (const auto &[key, value] : umap) {
      if (value.count == max_count)
        min_range = min(min_range, value.range.second - value.range.first + 1);
    }
    return min_range;
  }

 private:
  struct Record {
    int count;
    std::pair<int, int> range;
  };
};

int main() {
  vector<int> nums{1, 2, 2, 3, 1};
  Solution solution;
  solution.FindShortestSubArray(nums);
  return 0;
}