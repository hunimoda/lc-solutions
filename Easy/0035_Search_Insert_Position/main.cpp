#include <iostream>
#include <vector>


// Implement binary search algorithm
int search_insert(std::vector<int> &nums, int target) {

    int start { 0 };
    int end { static_cast<int>(nums.size()) - 1 };

    while (start <= end) {
        const int middle = (start + end) / 2;
        const int mid_value = nums.at(middle);

        if (mid_value > target) {
            end = middle - 1;
        } else if (mid_value < target) {
            start = middle + 1;
        } else {
            return middle;
        }
    }

    return start;

}


int main() {

    // Input # of elements
    int num_of_elem {};
    std::cout << "How many elem? ";
    std::cin >> num_of_elem;

    std::cout << "Input: ";

    // Input vector of integers
    std::vector<int> nums {};
    for (int i {}; i < num_of_elem; i++) {
        int elem {};
        std::cin >> elem;

        nums.push_back(elem);
    }

    // Input target value
    int target {};
    std::cout << "Target: ";
    std::cin >> target;

    // Show result
    std::cout << "Output: " << search_insert(nums, target)
            << std::endl;

    return 0;

}