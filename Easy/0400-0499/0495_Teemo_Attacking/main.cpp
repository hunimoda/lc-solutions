#include <vector>

using std::vector;

class Solution {
 public:
  int FindPoisonedDuration(vector<int> &time_series, int duration) {
    int total_duration = 0, t_end = -1;
    for (const int &time : time_series) {
      total_duration += duration;
      if (time <= t_end) total_duration -= t_end - time + 1;
      t_end = time + duration - 1;
    }
    return total_duration;
  }
};