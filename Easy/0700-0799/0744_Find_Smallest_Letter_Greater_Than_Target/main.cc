#include <vector>

using std::vector;

class Solution {
 public:
  char NextGreatestLetter(const vector<char> &letters, char target) {
    if (target >= letters.back() || target < letters.front())
      return letters.front();
    int i = 0;
    while (target >= letters[i]) i++;
    return letters[i];
  }
};