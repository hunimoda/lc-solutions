#include <iostream>
#include <string>
#include <queue>

class MyStack {
 private:
  int top_;
  std::queue<int> queue;

 public:
  MyStack() : top_(0) {}
  void Push(int x) {
    if (top_ != 0) {
      queue.push(top_);
      for (size_t i = 0; i < queue.size() - 1; i++) {
        queue.push(queue.front());
        queue.pop();
      }
    }
    top_ = x;
  }

  int Pop() {
    int temp_top = top_;
    if (queue.empty()) {
      top_ = 0;
    } else {
      top_ = queue.front();
      queue.pop();
    }
    return temp_top;
  }

  int Top() {
    return top_;
  }
  
  bool Empty() {
    return top_ == 0;
  }
};

int main() {
  MyStack stack;

  while (true) {
    std::string operation;
    std::cin >> operation;

    if (operation == "push") {
      int operand;
      std::cin >> operand;
      stack.Push(operand);
      std::cout << "\tPushed " << operand << std::endl;
    } else if (operation == "pop") {
      std::cout << "\tPoped " << stack.Pop() << std::endl;
    } else if (operation == "top") {
      std::cout << "\tTop is " << stack.Top() << std::endl;
    } else if (operation == "empty") {
      std::cout << "\tStack is " << (stack.Empty() ? "" : "NOT ") << "empty"
                << std::endl;
    } else if (operation == "exit") {
      break;
    } else {
      std::cout << "\tInvalid operation" << std::endl;
    }
  }

  return 0;
}