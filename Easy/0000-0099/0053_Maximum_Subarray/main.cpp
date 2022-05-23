#include <vector>


class Solution {

public:
    int max_sub_array(std::vector<int> &nums) {

        int global_max { nums.at(0) };
        int local_max  { nums.at(0) };

        for (int i { 1 }; i < nums.size(); i++) {
            local_max = std::max(
                local_max + nums.at(i), nums.at(i)
            );
            global_max = std::max(global_max, local_max);
        }

        return global_max;

    }

};