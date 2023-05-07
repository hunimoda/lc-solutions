#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  /** Store the result. */
  unsigned long long result;
  /** Shorten time for calculating power of 2's. */
  vector<unsigned long long> powerOf2_q;

 public:
  Solution() {
    // Initialize the vector 'powerOf2_q'
    const int q = static_cast<int>(1e5) / 32;
    unsigned long long power = 1;
    for (int _ = 0; _ < q + 1; _++) {
      powerOf2_q.push_back(power);
      power = Mod(power << 32);
    }
  }

  int numSubseq(vector<int> &nums, int target) {
    // Changing the order will not change the answer.
    sort(nums.begin(), nums.end());
    
    // Make i, j point the max element which is l.e. half the target value.
    int i, j;
    if (nums.back() <= target / 2) {
      i = j = nums.size() - 1;
    } else {
      for (j = 0; nums[j] <= target / 2; j++) {}
      i = --j;
    }

    // Count the # of subsequences widening the window(i ~ j) in each iteration.
    result = 0;
    while (i >= 0 && j < nums.size()) {
      Count(i, j);
      if (++j < nums.size()) {  // Move j towards the right.
        while (i >= 0 && nums[i] + nums[j] > target) {
          i--;  // Move i towards the left.
        }
      }
    }
    return static_cast<int>(result);
  }

 private:
  // Basically, calculate {2 ^ (i + 1) - 1} * {2 ^ (j - i - 1)}
  void Count(int i, int j) {
    unsigned long long partialSum = PowerOf2(i + 1) - 1;
    partialSum = Mod(partialSum * ((i < j) ? PowerOf2(j - i - 1) : 1));
    result = Mod(result + partialSum);
  }

  // Calculate power of 2 in O(1) operation using the vector 'powerOf2_q'.
  unsigned long long PowerOf2(int n) {
    return Mod(powerOf2_q[n / 32] << (n % 32));
  }

  // Return the mod of n.
  unsigned long long Mod(unsigned long long n) {
    return n % static_cast<int>(1e9 + 7);
  }
};