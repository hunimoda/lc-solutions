#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  int ArrayPairSum(vector<int> &nums) {
    RadixSort(nums);
    int sum = 0;
    for (int i = nums.size() - 2; i >= 0; i -= 2)
      sum += nums[i];
    return sum;
  }

 private:
  int GetNthDigit(int num, int n) {
    return (num >> (n << 3)) & 255;
  }

  void NegateSignBit(vector<int> &nums) {
    for (int &num : nums)
      num += 1 << 31;
  }

 public:
  void RadixSort(vector<int> &nums) {
    NegateSignBit(nums);
    for (int n = 0; n < 4; n++) {
      vector<vector<int>> buckets(256);
      for (const int &num : nums)
        buckets[GetNthDigit(num, n)].push_back(num);
      nums.clear();
      for (const auto &bucket : buckets)
        nums.insert(nums.end(), std::make_move_iterator(bucket.begin()),
                    std::make_move_iterator(bucket.end()));
    }
    NegateSignBit(nums);
  }
};

void PrintVectorElements(vector<int> &nums) {
  std::cout << "\n==== Print Vector Elements ====" << std::endl;
  for (const int &num : nums)
    std::cout << num << ' ';
  std::cout << std::endl;
}

int main() {
  Solution solution;
  vector<int> nums = 
      {5, 1, -3, -1285, 324, 34, -626, 3256, -514, -346, 434, -3513};
  PrintVectorElements(nums);
  solution.RadixSort(nums);
  PrintVectorElements(nums);
  return 0;
}