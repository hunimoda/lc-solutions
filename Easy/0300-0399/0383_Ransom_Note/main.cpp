#include <string>
#include <unordered_map>

using std::string;

class Solution {
 public:
  bool CanConstruct(string ransom_note, string magazine) {
    std::unordered_map<char, int> counter;
    for (const char &c : magazine)
      counter.count(c) ? counter[c]++ : counter[c] = 1;
    for (const char &c : ransom_note) {
      if (!counter.count(c) || counter[c] <= 0) return false;
      counter[c]--;
    }
    return true;
  }
};