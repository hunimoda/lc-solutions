#include <vector>


class Solution {

public:
    int max_sub_array(std::vector<int> &nums) {

        int max_sub_array_sum { std::numeric_limits<int>::min() };

        int curr_partial_sum { 0 };
        int min_partial_sum { 0 };

        const size_t nums_size { nums.size() };

        for (int num: nums) {
            curr_partial_sum += num;
            
            max_sub_array_sum = std::max(
                max_sub_array_sum, 
                curr_partial_sum - min_partial_sum
            );

            if (curr_partial_sum < min_partial_sum) {
                min_partial_sum = curr_partial_sum;
            }
        }

        return max_sub_array_sum;

    }

};