#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  vector<vector<int>> LargeGroupPositions(const string &s) {
    // Lee's version of code:
    //   fewer lines, easy to understand
    //   try to use better variables inside loop (different approach)
    vector<vector<int>> groups;
    for (int i = 0, j = 1; i < s.size(); i = j++) {
      while (j < s.size() && s[i] == s[j]) j++;
      if (j - i >= 3)
        groups.push_back({i, j - 1});
    }
    return groups;

    //// My version of code:
    ////   more lines, extra logic, bad use of variable selection in loop
    // vector<vector<int>> groups;
    // int start = 0, n = s.length();

    // for (int end = 1; end < n; end++) {
    //   if (s[end] == s[start]) continue;
    //   if (end - start >= 3)
    //     groups.push_back({start, end - 1});
    //   start = end;
    // }
    // if (n - start >= 3) groups.push_back({start, n - 1});

    // return groups;
  }
};