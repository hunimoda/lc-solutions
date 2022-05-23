#include <vector>


class Solution {

public:
    std::vector<int> plus_one(std::vector<int> &digits) {

        int carry_in { 1 };
        const int digits_size { static_cast<int>(digits.size()) };

        for (int i { digits_size - 1 }; i >= 0; i--) {
            int sum { digits.at(i) + carry_in };

            digits.at(i) = sum % 10;
            carry_in = sum / 10;

            if (carry_in == 0) return digits;
        }

        digits.insert(digits.begin(), 1);
        return digits;
        
    }

};