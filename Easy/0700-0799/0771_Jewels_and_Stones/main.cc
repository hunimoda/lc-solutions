#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
 public:
  int NumJewelsInStones(const string &jewels, const string &stones) {
    bool jewels_list[128] = { false };
    for (char jewel : jewels)
      jewels_list[jewel] = true;

    int count = 0;
    for (char stone : stones)
      if (jewels_list[stone]) count++;
    return count;
  }
};