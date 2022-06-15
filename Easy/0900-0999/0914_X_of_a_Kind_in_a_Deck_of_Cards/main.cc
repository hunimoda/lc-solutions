#include <vector>
#include <unordered_map>
#include <numeric>

using std::vector;
using std::unordered_map;
using std::gcd;

class Solution {
 public:
  bool HasGroupsSizeX(const vector<int> &deck) {
    unordered_map<int, int> freq;
    for (auto card : deck) freq[card]++;

    int X = 0;
    for (auto &p : freq) {
      X = gcd(X, p.second);
      if (X < 2) return false;
    }
    return true;
  }
};