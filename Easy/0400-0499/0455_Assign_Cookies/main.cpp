#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  int FindContentChildren(vector<int> &g, vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int content = 0;
    for (int gi = g.size() - 1, si = s.size() - 1; gi >= 0 && si >= 0; gi--)
      if (g[gi] <= s[si]) content++, si--;
    return content;
  }
};

int main() {
  vector<int> g{5, 4, 8, 7, 32, 2, 5, 7, 9, 9, 5, 3, 24, 4, 2, 3, 32, 15, 6,7 , 26, 4, 26, 7, 7,543, 43, 5, 7, 8, 5, 3};
  vector<int> s{15, 6, 7, 3, 54,  3, 6, 7, 7, 8, 8, 2, 6, 7, 7, 1, 1, 23,5, 7, 8, 75, 43, 5};
  Solution solution;
  std::cout << solution.FindContentChildren(g, s) << std::endl;
  return 0;
}