#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string Tictactoe(const vector<vector<int>> &moves) {
    vector<vector<int>> board(3, vector<int>(3, 0));
    bool is_a_playing = true;

    for (const auto &move : moves) {
      board[move[0]][move[1]] = is_a_playing ? 2 : 3;
      is_a_playing ^= true;
    }
  }
};