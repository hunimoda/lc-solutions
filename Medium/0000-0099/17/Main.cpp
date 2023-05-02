#include <vector>
#include <deque>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(const string &digits) {
    if (digits == "") return {};

    // Maps each digit to letters
    vector<string> keyMap = 
        { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    deque<string> combinations = { "" };

    for (char digit : digits) {
      // Iterate over current snapshot of the deque
      const size_t size = combinations.size();
      for (int _ = 0; _ < size; _++) {
        const string &front = combinations.front();
        for (char alpha : keyMap[digit - '2']) {
          // Append alphabets to current combination
          combinations.push_back(front + alpha);
        }
        combinations.pop_front();
      }
    }
    return vector<string>(combinations.begin(), combinations.end());
  }
};