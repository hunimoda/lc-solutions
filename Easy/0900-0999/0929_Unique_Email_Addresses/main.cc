#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
 public:
  int NumUniqueEmails(const vector<string> &emails) {
    unordered_set<string> uniq;
    for (const string &email : emails)
      uniq.insert(FormatEmail(email));
    return uniq.size();
  }

 private:
  string FormatEmail(const string &email) {
    string formatted;
    size_t at_pos = email.find("@");
    for (size_t i = 0; i < at_pos && email[i] != '+'; i++)
      if (email[i] != '.') formatted += email[i];
    formatted.insert(formatted.end(), email.begin() + at_pos, email.end());
    return formatted;
  }
};