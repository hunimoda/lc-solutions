#include <iostream>
#include <string>


class Solution {

public: 
    int length_of_last_word(std::string s) {

        int end { static_cast<int>(s.length()) - 1 };
        while (s.at(end) == ' ') end--;
        
        int start { end - 1 };
        while (start >= 0 && s.at(start) != ' ') start--;

        return (end - start);

    }

};


int main() {

    Solution solution;

    std::string s { "" };
    std::getline(std::cin, s);

    std::cout << solution.length_of_last_word(s) << std::endl;

    return 0;
    
}