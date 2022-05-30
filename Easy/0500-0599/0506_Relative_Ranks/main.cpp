#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using std::vector;
using std::string;

class Solution {
 public:
  vector<string> FindRelativeRanks(vector<int> &scores) {
    vector<int> copy(RadixSort(scores));

    std::unordered_map<int, string> umap;
    for (int i = 0; i < copy.size(); i++) {
      if (i < kMedals.size()) umap[copy[i]] = kMedals[i];
      else umap[copy[i]] = std::to_string(i + 1);
    }
    
    vector<string> ranks;
    for (const int score : scores)
      ranks.push_back(umap[score]);

    return ranks;
  }

  int NthDigit(int number, int n) {
    return static_cast<int>(number / std::pow(10, n)) % 10;
  }

  int DigitLength(int number) {
    if (number == 0) return 1;
    return static_cast<int>(std::log10(number)) + 1;
  }

  int LargestDigitLength(const vector<int> &v) {
    int largest_digit_length = 0;
    for (const int elem : v)
      largest_digit_length = std::max(largest_digit_length, DigitLength(elem));
    return largest_digit_length;
  }

  vector<int> RadixSort(const vector<int> &v) {
    vector<int> result(v);
    const int largest_digit_length = LargestDigitLength(result);
    for (int n = 0; n < largest_digit_length; n++) {
      vector<vector<int>> buckets(10);
      for (const int num : result)
        buckets[NthDigit(num, n)].push_back(num);
      result.clear();
      for (int i = 9; i >= 0; i--)
        result.insert(result.end(), buckets[i].begin(), buckets[i].end());
    }
    return result;
  }

 private:
  const vector<string> kMedals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
};

int main() {
  Solution solution;
  vector<int> v = {153, 24, 643, 64363, 23, 1, 6, 6434, 234};
  vector<int> w(solution.RadixSort(v));

  for (const int num : w)
    std::cout << num << ' ';
  std::cout << std::endl;
  return 0;
}