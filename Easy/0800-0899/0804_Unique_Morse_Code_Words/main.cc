#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
 public:
  int UniqueMorseRepresentations(vector<string> &words) {
    unordered_set<string> representations;
    for (const string &word : words)
      representations.insert(ToMorseCode(word));
    return representations.size();
  }

 private:
  const string kMorseCode[26] = {
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
      "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
      "..-", "...-", ".--", "-..-", "-.--", "--.."};

  string ToMorseCode(const string &word) {
    string morse = "";
    for (const char c : word)
      morse += kMorseCode[c - 'a'];
    return morse;
  } 
};