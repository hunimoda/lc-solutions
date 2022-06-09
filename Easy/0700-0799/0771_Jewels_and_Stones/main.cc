#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
 public:
  int NumJewelsInStones(const string &jewels, const string &stones) {
    int count = 0;
    unordered_set jewels_set(jewels.begin(), jewels.end());
    for (const auto &stone : stones)
      if (jewels_set.count(stone)) count++;
    return count;
  }
};