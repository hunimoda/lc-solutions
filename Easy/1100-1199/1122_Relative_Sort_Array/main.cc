#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::sort;

class Solution {
 public:
  vector<int> RelativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> freq;
    vector<int> unique, result;

    result.reserve(arr1.size());

    for (auto num : arr2) freq[num] = 0;
    for (auto num : arr1) {
      if (freq.count(num)) {
        freq[num]++;
      } else {
        unique.push_back(num);
      }
    }

    for (auto num : arr2)
      result.insert(result.end(), freq[num], num);
    sort(unique.begin(), unique.end());
    result.insert(result.end(), unique.begin(), unique.end());

    return result;
  }
};