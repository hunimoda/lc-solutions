#include <iostream>
#include <stack>

class MyQueue {
 private:
  std::stack<int> stack;
  std::stack<int> helper;

 public:
  MyQueue() {}

  void Push(int x) {
    const size_t kStackSize = stack.size();

    // Pop all elements: stack -> helper
    for (size_t i = 0; i < kStackSize; i++) {
      helper.push(stack.top());
      stack.pop();
    }

    // Push x into stack
    stack.push(x);

    // Push all elements back: helper -> stack
    for (size_t i = 0; i < kStackSize; i++) {
      stack.push(helper.top());
      helper.pop();
    }
  }

  int Pop() {
    int pop = Peek();
    stack.pop();
    return pop;
  }

  int Peek() { return stack.top(); }
  bool Empty() { return stack.empty(); }
};

int main() {
  MyQueue queue;
  std::cout << std::boolalpha;

  queue.Push(1);
  std::cout << queue.Peek() << std::endl;
  queue.Push(2);
  std::cout << queue.Peek() << std::endl;
  queue.Push(3);
  std::cout << queue.Peek() << std::endl;

  std::cout << "------------------------------" << std::endl;
  std::cout << queue.Pop() << std::endl;
  std::cout << queue.Peek() << std::endl;
  std::cout << queue.Pop() << std::endl;
  std::cout << queue.Peek() << std::endl;
  std::cout << queue.Pop() << std::endl;
  std::cout << queue.Peek() << std::endl;

  return 0;
}