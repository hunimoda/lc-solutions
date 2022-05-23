#include <iostream>
#include <string>
#include <queue>

class MyStack {
 private:
  std::queue<int> queue;

 public:
  MyStack() {}
  void Push(int x) {
    queue.push(x);
    for (size_t i = 0; i < queue.size() - 1; i++) {
      queue.push(queue.front());
      queue.pop();
    }
  }

  int Pop() {
    int pop = Top();
    queue.pop();
    return pop;
  }

  int Top() {
    return queue.front();
  }

  bool Empty() {
    return queue.empty();
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