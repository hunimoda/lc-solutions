#include <vector>

using std::vector;

class Solution {
 public:
  int NumEquivDominoPairs(vector<vector<int>> &dominoes) {
    int counter[10][10] = {};
    int pairs = 0;

    // populate counter to store the number of identical dominoes
    for (const auto &domino : dominoes)
      counter[domino[0]][domino[1]]++;
    for (int i = 1; i < 9; i++) {
      for (int j = i + 1; j <= 9; j++)
        counter[i][j] += counter[j][i];
    }

    // calculate number of identical pairs
    for (int i = 1; i <= 9; i++) {
      for (int j = i; j <= 9; j++)
        pairs += counter[i][j] * (counter[i][j] - 1) / 2;
    }

    return pairs;
  }
};