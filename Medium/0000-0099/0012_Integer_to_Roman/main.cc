#include <string>
#include <vector>
#include <array>

using std::string;
using std::vector;
using std::array;

// // by storing each digit as roman numeral
// class Solution {
//  public:
//   string IntToRoman(int num) {
//     string roman = "";
//     for (int pow = 3, place = 1000; num; pow--, place /= 10) {
//       roman += digit_to_roman_[pow][num / place];
//       num = num % place;
//     }
//     return roman;
//   }

//  private:
//   const vector<vector<string>> digit_to_roman_ = {
//       {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
//       {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
//       {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
//       {"", "M", "MM", "MMM"}};
// };

// w/o storing each digit as roman numeral
class Solution {
 public:
  string IntToRoman(int num) {
    string result = "";
    int place = 1'000;

    for (int i = sym_.size() - 1; i >= 0; i -= 2) {
      const int digit = num / place;
      if (digit == 4 || digit == 9) {
        result += sym_[i];
        result += (digit == 9) ? sym_[i + 2] : sym_[i + 1];
      } else {
        if (digit >= 5) result += sym_[i + 1];
        for (int j = digit % 5; j > 0; j--) result += sym_[i];
      }
      num -= digit * place;
      place /= 10;
    }
    return result;
  }

 private:
  const array<char, 7> sym_ = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
};

int main() {
  Solution s;
  s.IntToRoman(465);
  return 0;
}