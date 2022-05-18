#include <iostream>
#include <stack>
#include <chrono>

using namespace std::chrono;

class MyQueue {
 private:
  std::stack<int> in;
  std::stack<int> out;

 public:
  MyQueue() {}

  void Push(int x) { in.push(x); }

  int Pop() {
    int temp = Peek();
    out.pop();
    return temp;
  }

  int Peek() {
    if (out.empty()) {
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
    }
    return out.top();
  }

  bool Empty() {
    return in.empty() && out.empty();
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