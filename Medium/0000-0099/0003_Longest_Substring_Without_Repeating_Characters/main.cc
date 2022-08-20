#include <string>
#include <array>
#include <algorithm>

using std::string;
using std::array;
using std::max;

class Solution {
 public:
  int LengthOfLongestSubstring(const string &s) {
    array<int, 128> freq = {};
    const int n = s.length();
    int i = 0, j = 0, max_length = 0;

    while (j < n) {
      freq[s[j]] ? freq[s[i++]]-- : freq[s[j++]]++;
      max_length = max(max_length, j - i);
    }
    return max_length;
  }
};