#include <iostream>
#include <string>
using std::string;


class Solution {

public:
    string add_binary(string a, string b) {

        if (a.length() < b.length()) return add_binary(b, a);

        const int diff { (int) (a.length() - b.length()) };
        int carry_in { 0 };
        string sum_str { "" };

        for (int i { (int) a.length() - 1 }; i >= 0; i--) {
            int digit_a { a.at(i) - '0' };
            int digit_b {
                (i >= diff) ? b.at(i - diff) - '0' : 0
            };

            int sum = digit_a + digit_b + carry_in;
            sum_str = std::to_string(sum % 2) + sum_str;
            carry_in = sum / 2;
        }

        sum_str = (carry_in == 1 ? "1" : "") + sum_str;

        return sum_str;

    }

};


int main() {

    string a { "" };
    string b { "" };

    std::cin >> a;
    std::cin >> b;

    Solution solution;
    std::cout << "Output: " << solution.add_binary(a, b) << std::endl;

    return 0;

}