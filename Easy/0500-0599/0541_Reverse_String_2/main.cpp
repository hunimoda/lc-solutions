#include <string>

using std::string;

class Solution {
 public:
  string ReverseString(string s, int k) {
    const int s_size = s.size();
    for (int i_start = 0; i_start < s_size; i_start += 2*k) {
      const auto reverse_from = s.begin() + i_start;
      const auto reverse_to = reverse_from + std::min(k, s_size - i_start);
      std::reverse(reverse_from, reverse_to);
    }
    return s;
  }
};