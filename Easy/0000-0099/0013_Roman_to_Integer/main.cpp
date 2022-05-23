#include <iostream>
#include <string>


int symbol_to_value(const char symbol) {

    switch (symbol) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return -1;
    }

}


int roman_to_int(std::string roman) {

    int result_int {};
    const size_t roman_size { roman.size() };

    for (size_t i {}; i < roman_size; i++) {
        const char curr_sym { roman.at(i) };
        const int curr_value { symbol_to_value(curr_sym) };

        bool subtract {
            (i < roman_size - 1) &&
            curr_value < symbol_to_value(roman.at(i + 1))
        };

        result_int += (subtract ? -1 : 1) * curr_value;
    }

    return result_int;

}


int main() {

    std::string roman {};
    std::cout << "Input: ";
    std::cin >> roman;

    std::cout << "Output: " << roman_to_int(roman) << std::endl;

    return 0;

}