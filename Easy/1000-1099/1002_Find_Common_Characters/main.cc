#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::min;

class Solution {
 public:
  vector<string> CommonChars(vector<string> &words) {
    int counter[26];
    for (int i = 0; i < 26; i++) counter[i] = 100;

    for (const auto &word : words) {
      int temp[26] {};
      for (char c : word) temp[c - 'a']++;
      for (int i = 0; i < 26; i++)
        counter[i] = min(counter[i], temp[i]);
    }

    vector<string> result;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < counter[i]; j++)
        result.emplace_back(1, static_cast<char>('a' + i));
    }
    return result;
  }
};