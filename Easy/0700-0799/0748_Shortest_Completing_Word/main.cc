#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string ShortestCompletingWord(const string &license_plate,
                                const vector<string> &words) {
    // Format license_plate to contain only lowercase alphabets
    string plate = "";
    for (const char c : license_plate) {
      if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z')
        plate += std::tolower(c);
    }

    string scw = "0123456789abcdef";  // 16 chars
    for (const string &word : words) {
      // No need to proceed if current word is longer than or the same as scw
      if (word.length() >= scw.length()) continue;

      // Populate alphabet counter for each word
      int counter[26] = { 0 };
      for (const char c : word)
        counter[c - 'a']++;

      // Decrement counter by looping through lowercase-only plate
      bool completing = true;
      for (const char c : plate) {
        if (counter[c - 'a'] <= 0) {
          completing = false;
          break;
        }
        counter[c - 'a']--;
      }

      // If current word is a completing word, update scw
      if (completing) scw = word;
    }

    return scw;
  }
};