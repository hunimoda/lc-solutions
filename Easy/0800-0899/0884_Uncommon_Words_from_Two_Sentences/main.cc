#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using std::vector;
using std::string;
using std::istringstream;
using std::unordered_map;

class Solution {
 public:
  vector<string> UncommonFromSentences(const string &s1, const string &s2) {
    istringstream iss(s1 + " " + s2);
    unordered_map<string, int> counter;
    vector<string> uncommons;
    string word;

    while (iss >> word) counter[word]++;
    for (const auto &[word, count] : counter)
      if (count == 1) uncommons.push_back(word);
    return uncommons;
  }
};