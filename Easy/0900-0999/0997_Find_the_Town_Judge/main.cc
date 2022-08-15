#include <vector>

using std::vector;

class Solution {
 public:
  int FindJudge(int n, vector<vector<int>> &trusts) {
    vector<int> trusters(n + 1, 0);
    for (const auto &trust : trusts)
      trusters[trust[0]] = -1, trusters[trust[1]]++;
    for (int i = 1; i <= n; i++)
      if (trusters[i] == n - 1) return i;
    return -1;
  }
};