#include <vector>

using std::vector;

class Solution {
 public:
  int MinCostClimbingStairs(const vector<int> &cost) {
    const int stair_length = cost.size();
    vector<int> min_cost(stair_length);

    // Initial condition
    min_cost[stair_length - 1] = cost[stair_length - 1];
    min_cost[stair_length - 2] = cost[stair_length - 2];

    // Calculate min cost from the back towards front
    for (int i = stair_length - 3; i >= 0; i--)
      min_cost[i] = cost[i] + std::min(min_cost[i + 1], min_cost[i + 2]);

    return std::min(min_cost[0], min_cost[1]);
  }
};