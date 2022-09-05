#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using std::vector;
using std::string;
using std::pair;
using std::min;

class Solution {
 public:
  int MaxNumberOfBalloons(const string &text) {
    int freq[128] = {};
    for (char c : text) freq[c]++;
    return min({freq['a'], freq['b'], freq['l'] / 2, freq['n'], freq['o'] / 2});

    // for (int max_balloons = 0; ; max_balloons++) {
    //   for (auto &[alpha, count] : balloon) {
    //     if (freq[alpha] < count)
    //       return max_balloons;
    //     freq[alpha] -= count;
    //   }
    // }
    // return 0;
  }
};