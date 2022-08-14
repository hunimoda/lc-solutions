#include <vector>
#include <array>
#include <string>

using std::vector;
using std::array;
using std::string;

class Solution {
 public:
  int CountCharacters(vector<string> &words, const string &chars) {
    // populate frequency counter for chars
    for (int i = 0; i < kAlphaNum; i++) counter_[i] = 0;
    for (char c : chars) counter_[c - 'a']++;

    // check if each word is 'good'
    int result = 0;
    for (const string &word : words)
      if (IsGoodString(word)) result += word.length();
    return result;
  }

 private:
  static const int kAlphaNum = 26;
  array<int, kAlphaNum> counter_;

  bool IsGoodString(const string &word) {
    array<int, kAlphaNum> counter = {};
    for (char c : word) counter[c - 'a']++;
    for (int i = 0; i < kAlphaNum; i++)
      if (counter_[i] < counter[i]) return false;
    return true;
  }
};