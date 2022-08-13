#include <string>

using std::string;

class Solution {
 public:
  string DefangIpAddress(const string &address) {
    string result;
    for (char c : address)
      result += (c == '.') ? "[.]" : string(1, c);
    return result;
  }
};