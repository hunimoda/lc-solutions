#include <vector>

using std::vector;

class Solution {
 public:
  char NextGreatestLetter(const vector<char> &letters, char target) {
    if (target >= letters.back() || target < letters.front())
      return letters.front();

    int start = 1;
    int end = letters.size() - 1;
    while (start < end) {
      const int mid = start + (end - start) / 2;
      if (target >= letters[mid]) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return letters[start];
  }
};