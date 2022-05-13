#include <iostream>
#include <algorithm>
#include <string>
using std::string;


class Solution {

public:
    string add_binary(string a, string b) {

        string sum { "" };
        int carry { 0 };

        int idx_a { (int) a.length() - 1 };
        int idx_b { (int) b.length() - 1 };

        while (idx_a >= 0 || idx_b >= 0) {
            if (idx_a >= 0) carry += a[idx_a--] - '0';
            if (idx_b >= 0) carry += b[idx_b--] - '0';

            sum += (char) (carry % 2 + '0');
            carry /= 2;
        }
        
        if (carry) sum += '1';

        std::reverse(sum.begin(), sum.end());

        return sum;

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