#include <iostream>
#include <vector>

using std::vector;

class NumArray {
 public:
  NumArray(vector<int> &nums) {
    int partial_sum = 0;
    for (int num : nums)
      partial_sum_.push_back(partial_sum += num);
  }

  int SumRange(int left, int right) {
    return partial_sum_[right] - (left > 0 ? partial_sum_[left - 1] : 0);
  }

 private:
  vector<int> partial_sum_;
};

int main() {
  vector<int> nums{1, 2, 3, 4, 5};
  NumArray num_array(nums);
  std::cout << num_array.SumRange(0, 0) << std::endl;
  std::cout << num_array.SumRange(0, 1) << std::endl;
  std::cout << num_array.SumRange(0, 4) << std::endl;
  std::cout << num_array.SumRange(1, 3) << std::endl;
  std::cout << num_array.SumRange(1, 4) << std::endl;
  std::cout << num_array.SumRange(3, 4) << std::endl;
  return 0;
}