#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using std::vector;
using std::unordered_set;
using std::accumulate;

class Solution {
 public:
  vector<int> FairCandySwap(const vector<int> &me, const vector<int> &you) {
    unordered_set<int> your_set(you.begin(), you.end());
    int give_me = (accumulate(you.begin(), you.end(), 0) -
                   accumulate(me.begin(), me.end(), 0)) / 2;

    auto it = me.begin();
    while (!your_set.count(give_me + *it)) it++;
    return {*it, give_me + *it};
  }
};

int main() {
  Solution solution;
  vector<int> me{35, 17, 4, 24, 10}, you{63, 21};
  // vector<int> me{1, 1}, you{2, 2};
  vector<int> swap = solution.FairCandySwap(me, you);
  std::cout << swap[0] << ", " << swap[1] << std::endl;
  return 0;
}