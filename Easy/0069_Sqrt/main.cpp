#include <iostream>


class Solution {

public:
    int MySqrt(int x) {

        int k {};
        while ((long long) k * k <= x) k++;

        return (k - 1);

    }

};


int main() {

    int x {};
    std::cout << "Input: x = ";
    std::cin >> x;

    Solution solution;
    std::cout << "Output: " << solution.MySqrt(x) << std::endl;

    return 0;

}