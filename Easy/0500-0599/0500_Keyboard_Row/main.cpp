#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
 public:
  vector<string> FindWords(vector<string> &words) {
    vector<string> result;
    for (const string &word : words)
      if (CanTypeWithOneRow(word)) result.push_back(word);
    return result;
  }

 private:
  const vector<vector<char>> keyboard = {
    {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'}, 
    {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'}, 
    {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}
  };

  bool CanTypeWithOneRow(const string &word) {
    const int row = GetKeyboardRow(word[0]);
    for (size_t i = 1; i < word.length(); i++)
      if (GetKeyboardRow(word[i]) != row) return false;
    return true;
  }

  int GetKeyboardRow(char c) {
    c = std::toupper(c);
    for (int i = 0; i < 3; i++) {
      if (std::find(keyboard[i].begin(), keyboard[i].end(), c) !=
          keyboard[i].end()) {
        return i;
      }
    }
  }
};