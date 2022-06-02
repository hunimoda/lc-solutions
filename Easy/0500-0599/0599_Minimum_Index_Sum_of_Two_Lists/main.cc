#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
 public:
  vector<string> FindRestaurant(vector<string> &list1, vector<string> &list2) {
    unordered_map<string, int> indexes;
    const size_t list1_size = list1.size();
    const size_t list2_size = list2.size();

    for (size_t i = 0; i < list1_size; i++)
      indexes[list1[i]] = i;

    vector<string> common_list;
    int min_index_sum = std::numeric_limits<int>::max();

    for (size_t i = 0; i < list2_size; i++) {
      if (!indexes.count(list2[i])) continue;
      const int index_sum = indexes[list2[i]] + i;
      if (index_sum > min_index_sum) continue;
      if (index_sum < min_index_sum) {
        common_list.clear();
        min_index_sum = index_sum;
      }
      common_list.push_back(list2[i]);
    }
    return common_list;
  }
};