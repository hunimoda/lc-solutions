#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
 public:
  vector<int> FairCandySwap(const vector<int> &me, const vector<int> &you) {
    int give_me = 0;
    unordered_set<int> my_set, your_set;
    vector<int> swap;

    for (auto candy : me) give_me -= candy, my_set.insert(candy);
    for (auto candy : you) give_me += candy, your_set.insert(candy);
    give_me /= 2;

    auto it = my_set.begin();
    while (swap.empty()) {
      if (your_set.count(give_me + *it))
        swap = {*it, give_me + *it};
      it++;
    }
    return swap;
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