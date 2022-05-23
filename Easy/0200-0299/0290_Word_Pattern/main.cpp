#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using std::string;

class Solution {
 private:
  template <typename T1, typename T2>
  bool MatchesUnidirection(std::vector<T1> v1, std::vector<T2> v2) {
    if (v1.size() != v2.size()) return false;
    std::unordered_map<T1, T2> match;
    for (size_t i = 0; i < v1.size(); i++) {
      if (match.count(v1[i]) && match[v1[i]] != v2[i])
        return false;
      match[v1[i]] = v2[i];
    }
    return true;
  }

 public:
  bool WordPattern(string pattern, string s) {
    // Break string into vector
    std::vector<string> tokens;
    std::stringstream stream(s);
    string token;
    while (stream >> token)
      tokens.push_back(token);

    // Break pattern into vector
    std::vector<char> letters;
    for (char c : pattern)
      letters.push_back(c);

    return MatchesUnidirection(letters, tokens) &&
           MatchesUnidirection(tokens, letters);
  }
};

int main() {

}