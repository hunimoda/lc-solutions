#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Solution {
 public:
  int NumRookCaptures(vector<vector<char>> &board) {
    const pair<int, int> rook = FindRook(board);
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int captures = 0;

    for (const auto &direction : directions) {
      pair<int, int> next_move = rook;
      char block = 'R';

      do {
        next_move.first += direction.first;
        next_move.second += direction.second;
        if (!IsInBoard(next_move)) break;

        block = board[next_move.first][next_move.second];
      } while (block == '.');

      if (block == 'p') captures++;
    }

    return captures;
  }

  pair<int, int> FindRook(vector<vector<char>> &board) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++)
        if (board[i][j] == 'R') return {i, j};
    }
    return {-1, -1};
  }

  bool IsInBoard(pair<int, int> &position) {
    return 0 <= position.first && position.first < 8 &&
           0 <= position.second && position.second < 8;
  }
};