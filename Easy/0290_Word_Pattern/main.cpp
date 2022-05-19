#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using std::string;

class Solution {
 public:
  bool WordPattern(string pattern, string s) {
    // Break string s into vectors of strings separated by spaces
    std::vector<string> strings;
    std::stringstream stream(s);
    string token;
    while (stream >> token)
      strings.push_back(token);

    // Pattern doesn't match if pattern & string vector have different length
    if (pattern.size() != strings.size()) return false;

    // Check for bijection from pattern to string
    std::unordered_map<char, string> pattern_to_string;
    for (size_t i = 0; i < pattern.size(); i++) {
      if (pattern_to_string.count(pattern[i]) &&
          pattern_to_string[pattern[i]] != strings[i]) {
        return false;
      }
      pattern_to_string[pattern[i]] = strings[i];
    }

    // Check for bijection from string to pattern
    std::unordered_map<string, char> string_to_pattern;
    for (size_t i = 0; i < strings.size(); i++) {
      if (string_to_pattern.count(strings[i]) && 
          string_to_pattern[strings[i]] != pattern[i]) {
        return false;
      }
      string_to_pattern[strings[i]] = pattern[i];
    }
    return true;
  }
};

int main() {

}