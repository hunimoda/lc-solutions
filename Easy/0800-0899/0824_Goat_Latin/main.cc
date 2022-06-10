#include <string>
#include <sstream>
#include <set>
#include <cctype>

using std::string;
using std::istringstream;
using std::set;
using std::tolower;

class Solution {
 public:
  string ToGoatLatin(const string &sentence) {
    istringstream iss(sentence);
    string word, goat_latin;
    int word_count = 0;

    while (iss >> word) {
      // Insert "ma" at the end
      if (!kVowels.count(tolower(word[0]))) {
        word += word[0];
        word.erase(word.begin());
      }
      word += "ma";

      // Insert additional "a" depending on current count
      word_count++;
      for (int i = 0; i < word_count; i++)
        word += "a";
      goat_latin += word + " ";
    }
    goat_latin.pop_back();  // Delete whitespace at the back

    return goat_latin;
  }

 private:
  const set<char> kVowels{'a', 'e', 'i', 'o', 'u'};
};