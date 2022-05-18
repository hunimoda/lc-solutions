#include <iostream>
#include <stack>
#include <chrono>

using namespace std::chrono;

class MyQueue {
 private:
  std::stack<int> up;
  std::stack<int> down;

 public:
  MyQueue() {}

  void Push(int x) {
    if (up.empty()) {
      const size_t down_size = down.size();
      for (size_t i = 0; i < down_size; i++) {
        up.push(down.top());
        down.pop();
      }
    }
    up.push(x);
  }

  int Pop() {
    int temp = Peek();
    down.pop();
    return temp;
  }

  int Peek() {
    const size_t up_size = up.size();
    for (size_t i = 0; i < up_size; i++) {
      down.push(up.top());
      up.pop();
    }
    return down.top();
  }

  bool Empty() {
    return up.empty() && down.empty();
  }
};

int main() {
  MyQueue queue;
  auto start = high_resolution_clock::now();
  for (int i = 0; i < 100'000; i++)
    queue.Push(i);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  std::cout << duration.count() << "[us]" << std::endl;
  return 0;
}