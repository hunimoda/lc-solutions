#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  vector<int> DiStringMatch(string &s) {
    int start = 0, stop = s.length();
    vector<int> result;

    result.reserve(s.length() + 1);
    for (auto c : s)
      result.push_back(c == 'I' ? start++ : stop--);
    result.push_back(start);

    return result;
  }
};