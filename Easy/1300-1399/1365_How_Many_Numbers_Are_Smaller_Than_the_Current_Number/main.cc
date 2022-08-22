#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::sort;
using std::unordered_map;

class Solution {
 public:
  vector<int> SmallerNumbersThanCurrent(const vector<int> &nums) {
    vector<int> copy(nums);
    sort(copy.begin(), copy.end());

    const int n = copy.size();
    unordered_map<int, int> umap = {{copy.front(), 0}};
    for (int i = 1; i < n; i++)
      if (copy[i] != copy[i - 1]) umap[copy[i]] = i;

    vector<int> result;
    result.resize(n);
    for (int i = 0; i < n; i++) result[i] = umap[nums[i]];
    return result;
  }
};

int main() {
  vector<int> test_case = {8, 1, 2, 2, 3};
  Solution s;
  s.SmallerNumbersThanCurrent(test_case);
  return 0;
}