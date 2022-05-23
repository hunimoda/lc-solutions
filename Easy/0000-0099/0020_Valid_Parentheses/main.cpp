#include <iostream>
#include <string>
#include <stack>


bool is_valid(std::string s) {

    std::stack<char> stack;

    for (char c: s) {
        bool push { c == '(' || c == '[' || c == '{' };

        if (push) {
            stack.push(c);
        } else {
            if (stack.size() == 0) return false;

            char to_pop {};

            switch (c) {
                case ')': to_pop = '('; break;
                case ']': to_pop = '['; break;
                case '}': to_pop = '{'; break;
                default : return false;
            }

            if (stack.top() != to_pop) return false;

            stack.pop();
        }
    }

    return stack.empty();

}


int main() {

    std::string input {""};
    std::cout << "Input: ";
    std::cin >> input;

    std::cout << "Output: " << std::boolalpha
            << is_valid(input) << std::endl;

    return 0;

}