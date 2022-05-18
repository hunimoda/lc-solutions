#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 private:
  string MakeRangeOf(int start, int end) {
    string range = std::to_string(start);
    if (start != end)
      range += "->" + std::to_string(end);
    return range;
  }

 public:
  vector<string> SummaryRanges(vector<int> &nums) {
    vector<string> summary;
    if (!nums.size()) return summary;

    int start = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1] + 1) {
        summary.push_back(MakeRangeOf(start, nums[i - 1]));
        start = nums[i];
      }
    }
    summary.push_back(MakeRangeOf(start, nums.back()));
    return summary;
  }
};