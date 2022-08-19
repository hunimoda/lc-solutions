#include <string>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>

using std::string;
using std::vector;
using std::array;
using std::accumulate;
using std::count_if;

class Solution {
 public:
  Solution() {
    for (int year = 1972; year <= 2100; year += 4)
      if (IsLeapYear(year)) leap_years_.push_back(year);
  }

  string DayOfTheWeek(int day, int month, int year) {
    int days_this_year =
        accumulate(kNumOfDaysInMonth.begin(),
                   kNumOfDaysInMonth.begin() + month - 1, 0) + (day - 1);
    if (IsLeapYear(year) && month >= 3) days_this_year++;

    int total_days_passed = 365 * (year - 1970) + days_this_year;
    total_days_passed +=
        count_if(leap_years_.begin(), leap_years_.end(),
                 [year](int leap_year) { return leap_year < year; });

    int day_of_given_date =
        (kDayOf_1970_1_1 + total_days_passed) % kDayOfWeek.size();
    return kDayOfWeek[day_of_given_date];
  }

 private:
  vector<int> leap_years_;
  array<string, 7> kDayOfWeek = {
      "Sunday", "Monday", "Tuesday", "Wednesday",
      "Thursday", "Friday", "Saturday"};
  array<int, 12> kNumOfDaysInMonth =
      {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int kDayOf_1970_1_1 = 4;

  bool IsLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
  }
};