#include <vector>
#include <stack>
#include <unordered_map>

using std::vector;

class Solution {
 public:
  vector<int> NextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    std::unordered_map<int, int> umap;
    std::stack<int> stack;
    for (const int &num : nums2) {
      while (!stack.empty() && stack.top() < num)
        umap[stack.top()] = num, stack.pop();
      stack.push(num);
    }
    while (!stack.empty())
      umap[stack.top()] = -1, stack.pop();

    vector<int> next_greater_element;
    for (const int &num : nums1)
      next_greater_element.push_back(umap[num]);
    return next_greater_element;
  }
};