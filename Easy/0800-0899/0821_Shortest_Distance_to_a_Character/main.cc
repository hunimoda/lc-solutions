#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::min;
using std::abs;

class Solution {
 public:
  vector<int> ShortestToChar(const string &s, const char c) {
    const int length = s.length();
    vector<int> indices, distances(length);
    for (int i = 0; i < length; i++)
      if (s[i] == c) indices.push_back(i);
    indices.push_back(2 * length);

    int left = -length, right = indices[0];
    for (int i = 0, j = 1; i < length; i++) {
      if (i > right) left = right, right = indices[j++];
      distances[i] = min(abs(i - left), abs(i - right));
    }
    return distances;
  }
};

int main() {
  Solution solution;
  solution.ShortestToChar("loveleetcode", 'e');
  return 0;
}