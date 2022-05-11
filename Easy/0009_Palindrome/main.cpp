#include <iostream>
#include <string>

// Version 1) By converting x to a string
//bool is_palindrome(int x) {
//
//    std::string x_as_string { std::to_string(x) };
//    const size_t str_length { x_as_string.length() };
//
//    for (int i {}; i < str_length / 2; i++) {
//        if (x_as_string.at(i) != 
//                x_as_string.at(str_length - i - 1)) {
//            return false;
//        }
//    }
//
//    return true;
//
//}


// Version 2) Do not convert x to a string
bool is_palindrome(int x) {

    // x can't be a palindrome if it has '-' sign
    if (x < 0) return false;

    int x_copy {x};
    long long y {};

    // Save reversed integer into y
    while (x_copy > 0) {
        y *= 10;
        y += x_copy % 10;
        x_copy /= 10;
    }

    // Check if the reversed integer is the same
    return (x == y);

}

int main() {

    int x {};
    std::cin >> x;

    std::cout << std::boolalpha;
    std::cout << is_palindrome(x) << std::endl;

    return 0;

}