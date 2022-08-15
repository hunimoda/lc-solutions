#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
using std::accumulate;
using std::min;

class Solution {
 public:
  int DistanceBetweenBusStops(vector<int> &distances, int from, int to) {
    if (from > to) return DistanceBetweenBusStops(distances, to, from);
    if (from == to) return 0;

    int sum_of_distances = accumulate(distances.begin(), distances.end(), 0);
    int clockwise_distance =
        accumulate(distances.begin() + from, distances.begin() + to, 0);

    return min(sum_of_distances - clockwise_distance, clockwise_distance);
  }
};