#include <queue>

using std::queue;

class RecentCounter {
 public:
  int Ping(int t) {
    while (!calls.empty() && calls.front() < t - 3000)
      calls.pop();
    calls.push(t);
    return calls.size();
  }

 private:
  queue<int> calls;
};