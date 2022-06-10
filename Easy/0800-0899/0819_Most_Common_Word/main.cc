#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cctype>

using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::istringstream;
using std::ispunct;
using std::tolower;

class Solution {
 public:
  string MostCommonWord(string &paragraph, const vector<string> &banned) {
    for (char &c : paragraph)
      c = ispunct(c) ? ' ' : tolower(c);

    unordered_set<string> banned_set(banned.begin(), banned.end());
    unordered_map<string, int> word_counter;
    string word, most_common = "";
    istringstream iss(paragraph);

    while (iss >> word) {
      if (!banned_set.count(word) &&
          ++word_counter[word] > word_counter[most_common]) {
        most_common = word;
      }
    }
    return most_common;
  }
};

int main() {
  Solution solution;
  string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
  solution.MostCommonWord(paragraph, {"hit"});
  return 0;
}