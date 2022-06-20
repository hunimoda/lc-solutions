#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::sort;

class Solution {
 public:
  int SingleNumber(vector<int> &nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
  }
};

class Solution {
 public:
  int SingleNumber(vector<int> &nums) {
    unordered_set<int> uset;
    for (int num : nums) {
      if (uset.count(num)) {
        uset.erase(num);
      } else {
        uset.insert(num);
      }
    }
    return *uset.begin();
  }
};

class Solution {
 public:
  int SingleNumber(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (int num : nums) umap[num]++;
    auto it = umap.begin();
    while (it->second != 1) it++;
    return it->first;
  }
};

class Solution {
 public:
  int SingleNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int i = 0, j = 1;
    while (j < nums.size() && nums[i] == nums[j])
      i += 2, j += 2;
    return nums[i];
  }
};