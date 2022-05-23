#include <vector>


class Solution {

public:
    int remove_duplicates(std::vector<int> &nums, int target) {

        int i { -1 };

        for (int j { 0 }; j < nums.size(); j++) {
            if (nums.at(j) != target) {
                nums.at(++i) = nums.at(j);
            }
        }

        return (i + 1);

    }

};