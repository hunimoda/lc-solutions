#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  void ReverseString(vector<char> &s) {
    const size_t s_length = s.size();
    for (size_t i = 0; i < s_length / 2; i++)
      std::swap(s[i], s[s_length - i - 1]);
  }
};