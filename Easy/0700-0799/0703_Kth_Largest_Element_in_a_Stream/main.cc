#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class KthLargest {
 public:
  KthLargest(int k, vector<int> &nums) : k_(k) {
    std::sort(nums.begin(), nums.end(), std::greater<>());
    if (nums.size() > k) nums.resize(k);
    largest_elem = std::move(nums);
  }

  int Add(int value) {
    if (largest_elem.size() == 0 ||
        largest_elem.size() < k_ && value <= largest_elem.back()) {
      largest_elem.push_back(value);
    } else if (value > largest_elem.back()) {
      BinarySearchInsert(value);
    }
    return largest_elem.back();
  }

 private:
  vector<int> largest_elem;
  const int k_;

  void BinarySearchInsert(int value) {
    int start = 0, end = largest_elem.size() - 1;
    while (start < end) {
      const int mid = start + (end - start) / 2;
      if (value > largest_elem[mid]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    vector<int>::iterator it = largest_elem.begin();
    largest_elem.insert(it + start, value);
    if (largest_elem.size() > k_) largest_elem.resize(k_);
  }
};