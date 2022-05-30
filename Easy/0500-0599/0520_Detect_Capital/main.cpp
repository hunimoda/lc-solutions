#include <string>
#include <functional>

using std::string;

class Solution {
 public:
  bool DetectCapitalUse(string word) {
    if (word.length() == 1) return true;
    if (std::isupper(word[0]) && std::isupper(word[1]))
      return IsSameCaseFromSecondChar(word, "upper");
    return IsSameCaseFromSecondChar(word, "lower");
  }

 private:
  bool IsSameCaseFromSecondChar(string word, string letter_case) {
    int (*check_function)(int) =
        letter_case != "lower" ?
            static_cast<int(*)(int)>(std::islower) :
            static_cast<int(*)(int)>(std::isupper);
    for (size_t i = 1; i < word.size(); i++)
      if (check_function(word[i])) return false;
    return true;
  }
};