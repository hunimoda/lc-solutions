#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::istringstream;

class Solution {
 public:
  vector<string> FindOccurrences(string text, string first, string second) {
    vector<string> words, result;
    istringstream iss(text);
    string temp;

    // convert string into vector of strings
    while (iss >> temp)
      words.push_back(temp);

    // push 'third' into the vector
    for (int i = 0; i < words.size() - 2; i++) {
      if (words[i] == first && words[i + 1] == second)
        result.push_back(words[i + 2]);
    }

    return result;
  }
};