#include <string>
#include <unordered_map>

using std::string;

class Solution {
 public:
  int LongestPalindrome(string s) {
    std::unordered_map<char, int> counter;
    for (const char &c : s)
      counter.count(c) ? counter[c]++ : counter[c] = 1;

    int even_sum = 0;
    bool has_odd = false;
    for (const auto &it : counter) {
      even_sum += it.second;
      if (it.second & 1) even_sum--, has_odd = true;
    }
    return even_sum + (has_odd ? 1 : 0);
  }
};