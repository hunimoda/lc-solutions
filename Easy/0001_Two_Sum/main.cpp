#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> two_sum(std::vector<int> &nums, int target) {

    // Sort vector in ascending order
    sort(nums.begin(), nums.end());

    // Declare 2 pointers
    int left { 0 };
    int right { static_cast<int>(nums.size()) - 1 };

    // Search for combination that sums to target
    while (left < right) {
        const int curr_sum { nums.at(left) + nums.at(right) };

        if (curr_sum > target) right--;
        else if (curr_sum < target) left++;
        else return std::vector<int> {left, right};
    }

    return std::vector<int> { -1, -1 };

}

int main() {

    int num_of_elem {};
    std::cout << "How many elements? ";
    std::cin >> num_of_elem;

    std::vector<int> nums {};

    for (int i {}; i < num_of_elem; i++) {
        int elem {};
        std::cin >> elem;

        nums.push_back(elem);
    }

    int target {};
    std::cout << "Target: ";
    std::cin >> target;

    std::vector<int> indices {
        two_sum(nums, target)
    };
    std::cout << "Output: " << indices.at(0) << ' '
            << indices.at(1) << std::endl;

    return 0;

}