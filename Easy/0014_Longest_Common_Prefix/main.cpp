#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>


std::string longest_common_prefix(
        std::vector<std::string> &strs) {

    // Get min length of strs [O(n)]
    size_t min_length { std::numeric_limits<int>::max() };
    for (const std::string &str: strs) {
        min_length = std::min(min_length, str.length());
    }

    std::string common_prefix {""};
    // Loop for min_length times
    for (int i {}; i < min_length; i++) {
        for (int j {1}; j < strs.size(); j++) {
            if (strs.at(0).at(i) != strs.at(j).at(i)) {
                return common_prefix;
            }
        }

        common_prefix += strs.at(0).at(i);
    }

    return common_prefix;

}


int main() {

    int num_of_strings {};
    std::cout << "How many strings? ";
    std::cin >> num_of_strings;

    std::vector<std::string> strs {};
    for (int i {}; i < num_of_strings; i++) {
        std::string str {};
        std::cin >> str;

        strs.push_back(str);
    }

    std::cout << "Output: " << longest_common_prefix(strs) 
            << std::endl;

    return 0;

}