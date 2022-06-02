#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using std::vector;
using std::stack;

void PrintVector(const vector<int> &);

class Solution {
 public:
  int MaximumProduct(vector<int> &nums) {
    if (nums.size() == 3) return nums[0] * nums[1] * nums[2];

    vector<int> pos, neg;
    for (const int num : nums)
      num >= 0 ? pos.push_back(num) : neg.push_back(num);
    
    if (pos.size() == 0)
      return ProductOfExtremeValues(neg);
    if (pos.size() < 3) {
      return GetExtremeValues(pos, 1)[0] *
             ProductOfExtremeValues(neg, 2, false);
    }
    if (neg.size() < 2)
      return ProductOfExtremeValues(pos);

    vector<int> largest_pos = GetExtremeValues(pos);
    const int largest_pos_product = CalculateProduct(largest_pos);
    return std::max(largest_pos_product,
                    largest_pos[0] * ProductOfExtremeValues(neg, 2, false));
  }

 private:
  int ProductOfExtremeValues(const vector<int> &nums, const int count = 3,
                             bool is_largest = true) {
    return CalculateProduct(GetExtremeValues(nums, count, is_largest));
  }
  
  int CalculateProduct(const vector<int> &nums) {
    int product = 1;
    for (const int num : nums)
      product *= num;
    return product;
  }

  int CalculateProduct(vector<int> &&nums) {
    return CalculateProduct(nums);
  }

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

void PrintVector(const vector<int> &nums) {
  std::cout << "---- Print Vector----------------------------" << std::endl;
  std::cout << "  ";
  for (const int num : nums)
    std::cout << num << " ";
  std::cout << std::endl;
}

int main() {
  Solution solution;
  vector<int> nums{1, 6, 4, 2, -8, 9, 2, -4};
  solution.MaximumProduct(nums);
  return 0;
}