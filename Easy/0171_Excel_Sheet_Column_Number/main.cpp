#include <string>

class Solution {
 public:
  int TitleToNumber(std::string column_title) {
    std::reverse(column_title.begin(), column_title.end());
    int number = 0, radix = 1;
    for (char c: column_title) {
      number += radix * (c - 'A' + 1);
      radix *= kNumOfAlphabets;
    }
    return number;
  }

 private:
  static constexpr size_t kNumOfAlphabets = 26;
};