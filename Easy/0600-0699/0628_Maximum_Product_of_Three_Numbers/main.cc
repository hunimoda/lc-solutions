#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using std::vector;
using std::stack;

void PrintVector(const vector<int> &nums) {
  std::cout << "\n---- Print Vector -----------------------------" << std::endl;
  std::cout << "  ";
  for (const int num : nums)
    std::cout << num << " ";
  std::cout << std::endl;
}

class Solution {
 public:
  int MaximumProduct(vector<int> &nums) {
    vector<int> max_nums = GetExtremeValues(nums);
    vector<int> min_nums = GetExtremeValues(nums, 2, false);
    PrintVector(max_nums);
    PrintVector(min_nums);
    return std::max(max_nums[0] * max_nums[1] * max_nums[2],
                    max_nums[0] * min_nums[0] * min_nums[1]);
  }

 private:
  vector<int> GetExtremeValues(const vector<int> &nums, const int count = 3,
                               bool is_largest = true) {
    stack<int> s, temp;
    for (const int num : nums) {
      while (!s.empty() && (num > s.top() == is_largest))
        temp.push(s.top()), s.pop();
      s.push(num);
      while (!temp.empty())
        s.push(temp.top()), temp.pop();
      if (s.size() > count) s.pop();
    }

    vector<int> extreme;
    while (!s.empty())
      extreme.push_back(s.top()), s.pop();
    std::reverse(extreme.begin(), extreme.end());
    return extreme;
  }
};

int main() {
  Solution solution;
  vector<int> nums{-1, -2, -3, -4};
  solution.MaximumProduct(nums);
  return 0;
}