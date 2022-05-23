#include <vector>

class MinStack {
 public:
  MinStack() {
    min_values_.push_back(std::numeric_limits<int>::max());
  }

  void Push(int value) {
    values_.push_back(value);
    const int prev_min_value = min_values_[min_values_.size() - 1];
    min_values_.push_back(std::min(prev_min_value, value));
  }

  void Pop() {
    values_.pop_back();
    min_values_.pop_back();
  }

  int Top() { return values_[values_.size() - 1]; }

  int GetMin() { return min_values_[min_values_.size() - 1]; }

 private:
  std::vector<int> values_;
  std::vector<int> min_values_;
};