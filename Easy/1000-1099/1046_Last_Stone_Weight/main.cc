#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;
using std::sort;
using std::upper_bound;

// O(N^2) solution w/o priority queue
class Solution {
 public:
  int LastStoneWeight(const vector<int> &stones) {
    copy_ = stones;
    sort(copy_.begin(), copy_.end());

    int x, y;
    while (copy_.size() > 1) {
      y = copy_.back(), copy_.pop_back();
      x = copy_.back(), copy_.pop_back();
      if (x != y) InsertStone(y - x);
    }
    return copy_.size() ? copy_[0] : 0;
  }

 private:
  vector<int> copy_;

  void InsertStone(int stone) {
    copy_.insert(upper_bound(copy_.begin(), copy_.end(), stone), stone);
  }
};

// using priority queue
class Solution {
 public:
  int LastStoneWeight(const vector<int> &stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    int x, y;

    while (pq.size() > 1) {
      y = pq.top(), pq.pop();
      x = pq.top(), pq.pop();
      if (x != y) pq.push(y - x);
    }
    return pq.size() ? pq.top() : 0;
  }
};