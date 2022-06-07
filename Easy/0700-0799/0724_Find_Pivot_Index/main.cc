class Solution {
 public:
  int PivotIndex(const vector<int> &nums) {
    int left_sum = 0, right_sum = 0;
    const int nums_size = nums.size();

    for (auto num : nums)
      right_sum += num;
          
    for (int i = 0; i < nums_size; i++) {
      right_sum -= nums[i];
      if (left_sum == right_sum) return i;
      left_sum += nums[i];
    }
    return -1;
  }
};