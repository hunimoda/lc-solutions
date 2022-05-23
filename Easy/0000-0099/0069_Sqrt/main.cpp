#include <iostream>


class Solution {

private:
    int Square(int num) { return num * num; }

public:
    int MySqrt(int x) {

        int start { 0 };
        int end { 46'340 };

        while (start < end) {
            const int mid { (start + end) / 2 };

            if (x < Square(mid)) end = mid - 1;
            else if (x >= Square(mid + 1)) start = mid + 1;
            else return mid;
        }

        return start;

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