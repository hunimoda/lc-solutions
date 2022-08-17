#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::queue;
using std::count;

// TC: O(N), SC: O(N)
class Solution {
 public:
  void DuplicateZeros(vector<int> &arr) {
    queue<int> q;
    for (int i = 0; q.size() < arr.size(); i++) {
      q.push(arr[i]);
      if (!q.back()) q.push(0);
    }
    for (int i = 0; i < arr.size(); i++)
      arr[i] = q.front(), q.pop();
  }
};

class Solution {
 public:
  void DuplicateZeros(vector<int> &arr) {
    const int n = arr.size();
    int left = 0, right = 0;

    arr.resize(n + 1);
    while (right < n) right += arr[left++] ? 1 : 2;

    left--, right--;
    while (left >= 0) {
      arr[right--] = arr[left--];
      if (!arr[left + 1]) arr[right--] = 0;
    }
    arr.resize(n);
  }
};