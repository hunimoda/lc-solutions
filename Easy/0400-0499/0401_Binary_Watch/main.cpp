#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
  vector<string> ReadBinaryWatch(int turned_on) {
    vector<string> possible_times;
    const size_t i_start = std::max(0, turned_on - 6);
    const size_t i_end = std::min(3, turned_on);
    for (size_t i = i_start; i <= i_end; i++) {
      vector<string> combinations = CombineHourAndMinute(
          ReadBinaryWatchHour(i),
          ReadBinaryWatchMinute(turned_on - i));
      if (!combinations.size()) continue;
      for (const string &combination : combinations)
        possible_times.push_back(combination);
    }
    return possible_times;
  }

 private:
  vector<string> ReadBinaryWatchHour(int turned_on) {
    switch (turned_on) {
      case 0: return vector<string>{ "0" };
      case 1: return vector<string>{ "1", "2", "4", "8" };
      case 2: return vector<string>{ "3", "5", "6", "9", "10"};
      case 3: return vector<string>{ "7", "11" };
      default:
        return vector<string>{ };
    }
  }

  vector<string> ReadBinaryWatchMinute(int turned_on) {
    vector<string> possible_minutes;
    for (int min = 0; min < 60; min++) {
      if (__builtin_popcount(min) == turned_on) {
        string formatted = (min < 10 ? "0" : "") + std::to_string(min);
        possible_minutes.push_back(formatted);
      }
    }
    return possible_minutes;
  }

  vector<string> CombineHourAndMinute(vector<string> hours, 
                                      vector<string> minutes) {
      vector<string> combinations;
      if (!hours.size() || !minutes.size()) return combinations;
      for (const string &hour : hours)
        for (const string &minute : minutes)
          combinations.push_back(hour + ":" + minute);
      return combinations;
  }
};